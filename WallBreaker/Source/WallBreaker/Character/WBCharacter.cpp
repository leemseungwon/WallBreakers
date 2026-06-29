// Fill out your copyright notice in the Description page of Project Settings.


#include "WallBreaker/Character/WBCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interface/WBInteractableInterface.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "WBGameplayTags.h"
#include "NavigationSystem.h"
#include "Components/CapsuleComponent.h"
#include "WallBreaker/Compo/StateComponent.h"
#include "WallBreaker/Compo/ItemInventoryComponent.h"
#include "WallBreaker/Compo/WBCombatComponent.h"
#include "WallBreaker/Compo/FlashLightComponent.h"
#include "WallBreaker/Widget/WBPlayerHUDWidget.h"
#include "GameMode/WBGameMode.h"

// Sets default values
AWBCharacter::AWBCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 1000.f;
	SpringArm->SetRelativeRotation(FRotator(-90.f, 0.f, 0.f));
	
	SpringArm->bUsePawnControlRotation = true; 

	SpringArm->bInheritYaw = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	
	Camera->bUsePawnControlRotation = false; 

	StateComponent = CreateDefaultSubobject<UWBStateComponent>(TEXT("StateComponent"));
	CombatComponent = CreateDefaultSubobject<UWBCombatComponent>(TEXT("CombatComponent"));
	ItemInventoryComponent = CreateDefaultSubobject<UItemInventoryComponent>(TEXT("ItemInventoryComponent"));
	FlashComponent = CreateDefaultSubobject<UFlashLightComponent>(TEXT("FlashComponent"));

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->bOrientRotationToMovement = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
	}
}

// Called when the game starts or when spawned
void AWBCharacter::BeginPlay()
{
	Super::BeginPlay();

	CurrentHP = MaxHP;

	APlayerController* Pc = Cast<APlayerController>(Controller);
    if (Pc)
    {
        Pc->bShowMouseCursor = true;
    }

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	if (HUDWidgetClass)
	{
		if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			HUDWidgetInstance = CreateWidget<UWBPlayerHUDWidget>(PC, HUDWidgetClass);

			if (HUDWidgetInstance)
			{
				HUDWidgetInstance->AddToViewport();
			}
		}
	}
}

// Called every frame
void AWBCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

	FindBestInteractable();

	if (GetCharacterMovement() && GetCharacterMovement()->Velocity.SizeSquared() <= 10.f)
	{
		APlayerController* PC = Cast<APlayerController>(GetController());
		if (PC)
		{
			FVector MouseWorldLocation;
			FVector MouseWorldDirection;

			if (PC->DeprojectMousePositionToWorld(MouseWorldLocation, MouseWorldDirection))
			{
				FVector CharLocation = GetActorLocation();

				FPlane GroundPlane(CharLocation, FVector::UpVector);

				FVector IntersectionPoint = FMath::RayPlaneIntersection(MouseWorldLocation, MouseWorldDirection, GroundPlane);
				FVector LookDirection = IntersectionPoint - CharLocation;

				LookDirection.Z = 0.f;

				if (!LookDirection.IsNearlyZero())
				{
					FRotator TargetRotation = LookDirection.Rotation();
					FRotator CurrentRotation = GetActorRotation();

					FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, 8.0f);
					SetActorRotation(FRotator(0.f, NewRotation.Yaw, 0.f));
				}
			}
		}
	}

	float CurrentYaw = GetActorRotation().Yaw;
	float YawDelta = FMath::FindDeltaAngleDegrees(PreviousYaw, CurrentYaw);
	float TurnRate = YawDelta / DeltaTime;

	if (FMath::Abs(TurnRate) < 15.0f)
	{
		TurnRate = 0.0f;
	}

	float TargetTurnSpeed = FMath::Clamp(TurnRate / 90.0f, -1.0f, 1.0f);
	NormalizedTurnSpeed = FMath::FInterpTo(NormalizedTurnSpeed, TargetTurnSpeed, DeltaTime, 10.0f);

	PreviousYaw = CurrentYaw;
}

void AWBCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Started, this, &AWBCharacter::InputMove);
		EnhancedInputComponent->BindAction(RotateCameraAction, ETriggerEvent::Triggered, this, &AWBCharacter::InputRotateCamera);
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, this, &AWBCharacter::InputFire);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AWBCharacter::InputInteract);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Canceled, this, &AWBCharacter::InputEndInteract);
		EnhancedInputComponent->BindAction(ReloadAction, ETriggerEvent::Started, this, &AWBCharacter::InputReload);
	}
}

float AWBCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (bIsDead || ActualDamage <= 0.0f) return 0.0f;

	if (CombatComponent)
	{
		CombatComponent->CancelReload();
	}

	CurrentHP = FMath::Clamp(CurrentHP - ActualDamage, 0.0f, MaxHP);

	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC && HitCameraShakeClass)
	{
		PC->ClientStartCameraShake(HitCameraShakeClass);
	}

	if (CurrentHP <= 0.0f)
	{
		Die();
	}
	else
	{
		if (HitReactMontage)
		{
			PlayAnimMontage(HitReactMontage);
		}
	}

	if (HUDWidgetInstance)
	{
		HUDWidgetInstance->UpdateHP(CurrentHP, MaxHP);
	}

	return ActualDamage;
}

void AWBCharacter::Die()
{
	if (bIsDead) 
		return;

	bIsDead = true;

	UCapsuleComponent* CapsuleComp = GetCapsuleComponent();
	if (CapsuleComp)
	{
		CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->DisableMovement();
		GetCharacterMovement()->StopMovementImmediately();
	}

	if (DeathMontage)
	{
		PlayAnimMontage(DeathMontage);
	}

	if (GetController())
	{
		GetController()->UnPossess();
	}

	AWBGameMode* GameMode = Cast<AWBGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->OnPlayerDied();
	}
}

void AWBCharacter::InputMove()
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (!PC) return;

	FHitResult HitResult;
	if (PC->GetHitResultUnderCursor(ECC_Visibility, false, HitResult))
	{
		if (HitResult.Component.IsValid() && HitResult.Component->GetCollisionProfileName() == EnableRoofProfile)
		{
			UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
			if (NavSys)
			{
				FNavLocation ProjectedLocation;
				if (NavSys->ProjectPointToNavigation(HitResult.ImpactPoint, ProjectedLocation, FVector(100.f)))
				{
					if (StateComponent)
					{
						StateComponent->IssueCommand(WBGameplayTag::Character_State_GeneralAction, ProjectedLocation.Location, nullptr);
					}
				}
			}
		}
	}
}

void AWBCharacter::InputRotateCamera(const FInputActionValue& Value)
{
	float RotationAxis = Value.Get<float>();
	
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		PC->AddYawInput(RotationAxis * CameraRotationSpeed * GetWorld()->GetDeltaSeconds());
	}
}

void AWBCharacter::InputInteract()
{
	if (TargetInteractableActor && TargetInteractableActor->GetClass()->ImplementsInterface(UWBInteractableInterface::StaticClass()))
	{
		InteractingActor = TargetInteractableActor;
		IWBInteractableInterface::Execute_OnInteract(TargetInteractableActor, this);
	}
}

void AWBCharacter::InputEndInteract()
{
	if (InteractingActor && InteractingActor->GetClass()->ImplementsInterface(UWBInteractableInterface::StaticClass()))
	{
		IWBInteractableInterface::Execute_OnEndInteract(InteractingActor, this);
		InteractingActor = nullptr;
	}
}

void AWBCharacter::FindBestInteractable()
{
	FVector SearchOrigin = GetActorLocation();
	TArray<AActor*> OverlappingActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);

	UKismetSystemLibrary::SphereOverlapActors(
		GetWorld(),
		SearchOrigin,
		InteractionRange,
		ObjectTypes,
		nullptr,
		ActorsToIgnore,
		OverlappingActors
	);

	AActor* BestTarget = nullptr;
	float ClosestDistance = InteractionRange;

	for (AActor* OverlappedActor : OverlappingActors)
	{
		if (OverlappedActor && OverlappedActor->GetClass()->ImplementsInterface(UWBInteractableInterface::StaticClass()))
		{
			float CurrentDist = FVector::Dist(SearchOrigin, OverlappedActor->GetActorLocation());
			if (CurrentDist < ClosestDistance)
			{
				ClosestDistance = CurrentDist;
				BestTarget = OverlappedActor;
			}
		}
	}

	TargetInteractableActor = BestTarget;
}

void AWBCharacter::InputFire()
{
	if (CombatComponent)
	{
		CombatComponent->FireWeapon();
	}
}

void AWBCharacter::InputReload()
{
	if (CombatComponent)
	{
		CombatComponent->ReloadWeapon();
	}
}

void AWBCharacter::NotifyControllerChanged()
{
}

void AWBCharacter::PlayActionMontage(UAnimMontage* Montage)
{
	if (GetMesh() && GetMesh()->GetAnimInstance())
	{
		GetMesh()->GetAnimInstance()->Montage_Play(Montage);
	}
}
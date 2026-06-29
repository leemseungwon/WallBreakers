// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WBEnemy.h"
#include "WallBreaker/Character/WBEnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "BrainComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "GameMode/WBGameMode.h"

// Sets default values
AWBEnemy::AWBEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AWBEnemyAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(GetMesh(), WeaponSocketName);

	bUseControllerRotationYaw = false;

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 360.0f, 0.0f);
	}

	CurrentHP = MaxHP;
}

void AWBEnemy::BeginPlay()
{
	Super::BeginPlay();

	SpawnLocation = GetActorLocation();
	CurrentHP = MaxHP;

	if (GetMesh() && WeaponMesh)
	{
		WeaponMesh->AttachToComponent(
			GetMesh(),
			FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			WeaponSocketName
		);
	}
}

void AWBEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsDead) return;

	AWBEnemyAIController* AIC = Cast<AWBEnemyAIController>(GetController());
	if (AIC)
	{
		UBlackboardComponent* BBComp = AIC->GetBlackboardComponent();
		if (BBComp)
		{
			AActor* TargetActor = Cast<AActor>(BBComp->GetValueAsObject(TEXT("TargetActor")));
			if (TargetActor)
			{
				if (GetCharacterMovement())
				{
					GetCharacterMovement()->bOrientRotationToMovement = false;
				}

				FVector TargetLoc = TargetActor->GetActorLocation();
				FVector OwnerLoc = GetActorLocation();
				FVector LookDir = TargetLoc - OwnerLoc;
				LookDir.Z = 0.0f;

				if (!LookDir.IsNearlyZero())
				{
					FRotator TargetRotation = LookDir.Rotation();
					FRotator CurrentRotation = GetActorRotation();

					FRotator SmoothRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, 10.0f);
					SetActorRotation(FRotator(0.f, SmoothRotation.Yaw, 0.f));
				}
			}
			else
			{
				if (GetCharacterMovement())
				{
					GetCharacterMovement()->bOrientRotationToMovement = true;
				}
			}
		}
	}
}

void AWBEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float AWBEnemy::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (bIsDead || ActualDamage <= 0.0f) return 0.0f;

	CurrentHP = FMath::Clamp(CurrentHP - ActualDamage, 0.0f, MaxHP);

	if (DamageCauser)
	{
		AWBEnemyAIController* AIC = Cast<AWBEnemyAIController>(GetController());
		if (AIC)
		{
			UBlackboardComponent* BBComp = AIC->GetBlackboardComponent();
			if (BBComp)
			{
				BBComp->SetValueAsObject(TEXT("TargetActor"), DamageCauser);
			}
		}
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

	return ActualDamage;
}

void AWBEnemy::Die()
{
	if (bIsDead) return;

	bIsDead = true;

	//UCapsuleComponent* CapsuleComp = GetCapsuleComponent();
	//if (CapsuleComp)
	//{
	//	CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//}

	if (GetMesh())
	{
		GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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

	AWBEnemyAIController* AIC = Cast<AWBEnemyAIController>(GetController());
	if (AIC)
	{
		AIC->ClearFocus(EAIFocusPriority::Gameplay);
		AIC->StopMovement();

		UBrainComponent* BrainComp = AIC->GetBrainComponent();
		if (BrainComp)
		{
			BrainComp->StopLogic(TEXT("Dead"));
		}

		AIC->UnPossess();
	}

	AWBGameMode* GameMode = Cast<AWBGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->KilledTerrorists++;
	}
}

void AWBEnemy::Attack(AActor* Target)
{
	if (!Target || bIsDead) return;

	FVector StartLoc = GetActorLocation() + (GetActorForwardVector() * 40.0f) + FVector(0.0f, 0.0f, 50.0f);
	if (WeaponMesh && WeaponMesh->DoesSocketExist(MuzzleSocketName))
	{
		StartLoc = WeaponMesh->GetSocketLocation(MuzzleSocketName);
	}

	FVector EndLoc = Target->GetActorLocation();
	ACharacter* TargetChar = Cast<ACharacter>(Target);
	if (TargetChar)
	{
		EndLoc = TargetChar->GetActorLocation();
	}

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLoc, EndLoc, ECC_Visibility, CollisionParams);
	FVector VisualEndLoc = bHit ? HitResult.ImpactPoint : EndLoc;

	if (bHit && HitResult.GetActor() != Target)
	{
		return;
	}

	if (AttackMontage)
	{
		PlayAnimMontage(AttackMontage);
	}

	DrawDebugLine(GetWorld(), StartLoc, VisualEndLoc, FColor::Red, false, 1.5f, 0, 3.0f);

	if (TracerEffect)
	{
		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			GetWorld(),
			TracerEffect,
			StartLoc,
			FRotator::ZeroRotator
		);

		if (NiagaraComp)
		{
			NiagaraComp->SetVariablePosition(TEXT("BeamStart"), StartLoc);
			NiagaraComp->SetVariablePosition(TEXT("BeamEnd"), VisualEndLoc);
		}
	}

	UGameplayStatics::ApplyDamage(
		Target,
		AttackDamage,
		GetController(),
		this,
		UDamageType::StaticClass()
	);
}
#include "StateComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "AIController.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UWBStateComponent::UWBStateComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    bMovementInputEnabled = true;
}

// Called when the game starts
void UWBStateComponent::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void UWBStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (CurrentState == WBGameplayTag::Character_State_GeneralAction && bMovementInputEnabled)
    {
        HandleMovement();
    }
}

void UWBStateComponent::ClearCurrentState()
{
    if (CurrentState == WBGameplayTag::Character_State_Death)
    {
        return;
    }

    CurrentState = FGameplayTag::EmptyTag;
}

bool UWBStateComponent::IsCurrentStateEqualToAny(const FGameplayTagContainer& TagsToCheck) const
{
    return TagsToCheck.HasTagExact(CurrentState);
}

void UWBStateComponent::ToggleMovementInput(bool bEnabled, float Duration)
{
    if (bEnabled)
    {
        FLatentActionInfo LatentAction;
        LatentAction.CallbackTarget = this;
        LatentAction.ExecutionFunction = "MovementInputEnableAction";
        LatentAction.Linkage = 0;
        LatentAction.UUID = 0;

        UKismetSystemLibrary::RetriggerableDelay(GetWorld(), Duration, LatentAction);
    }
    else
    {
        bMovementInputEnabled = false;
    }
}

void UWBStateComponent::MovementInputEnableAction()
{
    bMovementInputEnabled = true;
    ClearCurrentState();
}

void UWBStateComponent::IssueCommand(FGameplayTag CommandTag, FVector Location, AActor* Target)
{
    CurrentTargetLocation = Location;
    CurrentTargetActor = Target;
    SetCurrentState(CommandTag);

    ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
    if (!OwnerCharacter) return;

    APlayerController* PC = Cast<APlayerController>(OwnerCharacter->GetController());
    if (!PC) return;

    if (AAIController* AIC = Cast<AAIController>(OwnerCharacter->GetController()))
    {
        AIC->StopMovement();
    }
    else
    {
        PC->StopMovement();
    }

    UAIBlueprintHelperLibrary::SimpleMoveToLocation(PC, CurrentTargetLocation);
}

void UWBStateComponent::HandleMovement()
{
    ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
    if (!OwnerCharacter || !OwnerCharacter->GetCharacterMovement()) 
        return;

    APlayerController* PC = Cast<APlayerController>(OwnerCharacter->GetController());
    if (!PC) 
        return;

    FVector CharLocation = OwnerCharacter->GetActorLocation();
    FVector TargetLocation = CurrentTargetLocation;

    CharLocation.Z = 0.f;
    TargetLocation.Z = 0.f;

    float Distance = FVector::Dist(CharLocation, TargetLocation);

    if (Distance <= 40.0f)
    {
        OwnerCharacter->GetCharacterMovement()->StopMovementImmediately();
        ClearCurrentState();

        FHitResult HitResult;
        if (PC->GetHitResultUnderCursor(ECC_Visibility, false, HitResult))
        {
            FVector MouseLocation = HitResult.ImpactPoint;
            FVector CurrentLoc = OwnerCharacter->GetActorLocation();
            MouseLocation.Z = CurrentLoc.Z;

            FVector LookDirection = MouseLocation - CurrentLoc;
            if (!LookDirection.IsNearlyZero())
            {
                FRotator TargetRotation = LookDirection.Rotation();
                FRotator NewRotation = FMath::RInterpTo(OwnerCharacter->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 8.0f);
                OwnerCharacter->SetActorRotation(FRotator(0.f, NewRotation.Yaw, 0.f));
            }
        }
    }
    else
    {
        FVector MoveDir = OwnerCharacter->GetCharacterMovement()->Velocity;
        MoveDir.Z = 0.f;

        if (!MoveDir.IsNearlyZero())
        {
            FRotator TargetRotation = MoveDir.Rotation();
            FRotator NewRotation = FMath::RInterpTo(OwnerCharacter->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 10.0f);
            OwnerCharacter->SetActorRotation(FRotator(0.f, NewRotation.Yaw, 0.f));
        }
    }
}
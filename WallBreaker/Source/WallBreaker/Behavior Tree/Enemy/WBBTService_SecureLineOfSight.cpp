// Fill out your copyright notice in the Description page of Project Settings.


#include "Behavior Tree/Enemy/WBBTService_SecureLineOfSight.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "Character/WBEnemy.h"
#include "Character/WBCharacter.h"
#include "Kismet/GameplayStatics.h"

UWBBTService_SecureLineOfSight::UWBBTService_SecureLineOfSight()
{
	NodeName = TEXT("Secure Line Of Sight");
	Interval = 0.3f; // 빠른 반응을 위해 0.3초 주기로 체크합니다.
    bNotifyTick = true;
	RandomDeviation = 0.05f;
}

void UWBBTService_SecureLineOfSight::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn* OwnerPawn = OwnerComp.GetAIOwner()->GetPawn();
    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

    if (!OwnerPawn || !BlackboardComp) return;

    AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject(TargetKey.SelectedKeyName));
    if (!TargetActor)
        return;

    FHitResult HitResult;
    FVector Start = OwnerPawn->GetActorLocation();
    FVector End = TargetActor->GetActorLocation();

    FCollisionQueryParams Params;
    Params.AddIgnoredActor(OwnerPawn);

    bool bIsHit = GetWorld()->LineTraceSingleByChannel(
        HitResult,
        Start,
        End,
        ECC_Visibility,
        Params
    );

    bool bIsBlocked = bIsHit && (HitResult.GetActor() != TargetActor);

    BlackboardComp->SetValueAsBool(IsBlockedKey.SelectedKeyName, bIsBlocked);

    DrawDebugLine(GetWorld(), Start, End, bIsBlocked ? FColor::Red : FColor::Green, false, 0.1f, 0, 2.0f);
}
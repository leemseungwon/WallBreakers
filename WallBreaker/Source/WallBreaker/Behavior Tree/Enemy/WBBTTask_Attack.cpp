// Fill out your copyright notice in the Description page of Project Settings.


#include "Behavior Tree/Enemy/WBBTTask_Attack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "WallBreaker/Character/WBEnemy.h"
#include "WallBreaker/Character/WBCharacter.h"

UWBBTTask_Attack::UWBBTTask_Attack()
{
	NodeName = TEXT("Attack Player");
}

EBTNodeResult::Type UWBBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Error, TEXT("ExecuteTask Attack"));
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		return EBTNodeResult::Failed;
	}

	AWBEnemy* Enemy = Cast<AWBEnemy>(AIController->GetPawn());
	if (!Enemy) 
	{
		return EBTNodeResult::Failed;
	}

	AActor* TargetActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey()));
	if (!TargetActor)
	{
		return EBTNodeResult::Failed;
	}

	Enemy->Attack(TargetActor);

	return EBTNodeResult::Succeeded;
}
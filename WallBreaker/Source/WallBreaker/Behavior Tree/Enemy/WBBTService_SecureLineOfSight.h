// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "WBBTService_SecureLineOfSight.generated.h"

/**
 * 
 */
UCLASS()
class WALLBREAKER_API UWBBTService_SecureLineOfSight : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UWBBTService_SecureLineOfSight();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector TargetKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector IsBlockedKey;
};
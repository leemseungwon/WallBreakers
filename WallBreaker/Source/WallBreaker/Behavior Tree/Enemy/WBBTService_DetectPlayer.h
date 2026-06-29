// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "WBBTService_DetectPlayer.generated.h"

/**
 * 
 */
UCLASS()
class WALLBREAKER_API UWBBTService_DetectPlayer : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UWBBTService_DetectPlayer();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	// 플레이어를 감지할 반경
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float DetectRadius = 800.0f;
	
};

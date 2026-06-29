// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "WBEnemyAIController.generated.h"

UCLASS()
class WALLBREAKER_API AWBEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AWBEnemyAIController();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	UPROPERTY(VisibleAnywhere, Category = "AI")
	TObjectPtr<class UBehaviorTreeComponent> BehaviorTreeComponent;

	UPROPERTY(VisibleAnywhere, Category = "AI")
	TObjectPtr<class UBlackboardComponent> BlackboardComponent;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WallBreaker/WBGameplayTags.h"
#include "GameplayTagContainer.h"
#include "StateComponent.generated.h"


UCLASS()

class WALLBREAKER_API UWBStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWBStateComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	FORCEINLINE void SetCurrentState(const FGameplayTag NewState)
	{
		if (CurrentState == WBGameplayTag::Character_State_Death)
		{
			return;
		}

		CurrentState = NewState;
	}

	FORCEINLINE FGameplayTag GetCurrentState() const { return CurrentState; }

	void ClearCurrentState();

	bool IsCurrentStateEqualToAny(const FGameplayTagContainer& TagsToCheck) const;

public:
	FORCEINLINE bool MovementInputEnabled() { return bMovementInputEnabled; }

	void ToggleMovementInput(bool bEnabled, float Duration = 0.f);

	UFUNCTION()
	void MovementInputEnableAction();

	void IssueCommand(FGameplayTag CommandTag, FVector Location, AActor* Target = nullptr);

protected:
	void HandleMovement();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = State)
	FGameplayTag CurrentState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = State)
	bool bMovementInputEnabled = true;

	UPROPERTY()
	FVector CurrentTargetLocation;

	UPROPERTY()
	AActor* CurrentTargetActor;
};

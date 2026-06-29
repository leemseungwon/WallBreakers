// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WBEnemyAnimInstance.generated.h"

class AWBEnemy;
class UCharacterMovementComponent;

UCLASS()
class WALLBREAKER_API UWBEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UWBEnemyAnimInstance();

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UFUNCTION()
	void AnimNotify_EnemyDieComplete(UAnimNotify* Notify);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	bool bIsFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	bool bIsAccelerating;

private:
	UPROPERTY()
	TObjectPtr<AWBEnemy> EnemyCharacter;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> MovementComponent;
};

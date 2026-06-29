// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WBPlayerAnimInstance.generated.h"

class AWBCharacter;
class UWBCombatComponent;

UCLASS()
class WALLBREAKER_API UWBPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UWBPlayerAnimInstance();

	virtual void NativeInitializeAnimation() override;

protected:
	UFUNCTION()
	void AnimNotify_PlayerReloadComplete(UAnimNotify* Notify);

private:
	UPROPERTY()
	TObjectPtr<class AWBCharacter> PlayerCharacter;

	UPROPERTY()
	TObjectPtr<class UWBCombatComponent> CombatComponent;
};

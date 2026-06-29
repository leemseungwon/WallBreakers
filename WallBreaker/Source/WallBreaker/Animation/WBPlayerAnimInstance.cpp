// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/WBPlayerAnimInstance.h"
#include "Character/WBCharacter.h"
#include "WallBreaker/Compo/WBCombatComponent.h"

UWBPlayerAnimInstance::UWBPlayerAnimInstance()
{
}

void UWBPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	PlayerCharacter = Cast<AWBCharacter>(TryGetPawnOwner());
	if (PlayerCharacter)
	{
		CombatComponent = PlayerCharacter->GetComponentByClass<UWBCombatComponent>();
	}
}

void UWBPlayerAnimInstance::AnimNotify_PlayerReloadComplete(UAnimNotify* Notify)
{
	if (!CombatComponent && PlayerCharacter)
	{
		CombatComponent = PlayerCharacter->GetComponentByClass<UWBCombatComponent>();
	}

	if (CombatComponent)
	{
		CombatComponent->FinishReload();
		UE_LOG(LogTemp, Log, TEXT("[AnimInstance] C++ 네이티브 노티파이 감지: 장전 연동 완료"));
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/WBEnemyAnimInstance.h"
#include "Character/WBEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"

UWBEnemyAnimInstance::UWBEnemyAnimInstance()
{
	Speed = 0.0f;
	bIsFalling = false;
	bIsAccelerating = false;
}

void UWBEnemyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	EnemyCharacter = Cast<AWBEnemy>(TryGetPawnOwner());
	if (EnemyCharacter)
	{
		MovementComponent = EnemyCharacter->GetCharacterMovement();
	}
}

void UWBEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!EnemyCharacter)
	{
		EnemyCharacter = Cast<AWBEnemy>(TryGetPawnOwner());
		if (EnemyCharacter)
		{
			MovementComponent = EnemyCharacter->GetCharacterMovement();
		}
	}

	if (!EnemyCharacter || !MovementComponent)
		return;

	FVector Velocity = EnemyCharacter->GetVelocity();
	Velocity.Z = 0.0f;
	Speed = Velocity.Size();

	bIsFalling = MovementComponent->IsFalling();

	bIsAccelerating = (MovementComponent->GetCurrentAcceleration().SizeSquared() > 0.f);
}

void UWBEnemyAnimInstance::AnimNotify_EnemyDieComplete(UAnimNotify* Notify)
{
	AWBEnemy* Enemy = Cast<AWBEnemy>(TryGetPawnOwner());
	if (Enemy)
	{
		Enemy->Destroy();
	}
}

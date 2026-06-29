// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WBEnemy.generated.h"

class UBehaviorTree;
class UNiagaraSystem;
class UAnimMontage;

UCLASS()
class WALLBREAKER_API AWBEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWBEnemy();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

public:
	FORCEINLINE UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }

	void Attack(AActor* Target);

	FORCEINLINE FVector GetSpawnLocation() const { return SpawnLocation; }

	FORCEINLINE bool IsDead() const { return bIsDead; }

protected:
	void Die();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<UAnimMontage> AttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float AttackDamage = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Effects")
	TObjectPtr<UNiagaraSystem> TracerEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	FName WeaponSocketName = TEXT("WeaponSocket");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	FName MuzzleSocketName = TEXT("Muzzle");

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Stats")
	float MaxHP = 50.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat|Stats")
	float CurrentHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Montage")
	TObjectPtr<UAnimMontage> HitReactMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Montage")
	TObjectPtr<UAnimMontage> DeathMontage;

	UPROPERTY(BlueprintReadOnly, Category = "Combat|Stats")
	bool bIsDead = false;

public:
	UPROPERTY(BlueprintReadOnly, Category = "AI|Movement")
	FVector SpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Movement")
	float DetectRange = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Movement")
	float LoseRange = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Movement")
	float MaxChaseDistanceFromSpawn = 2000.0f;
};
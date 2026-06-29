// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Enum/ItemType.h"
#include "WBCombatComponent.generated.h"

class AWBEquipment;
class AWBCharacter;
class UAnimMontage;

UCLASS()
class WALLBREAKER_API UWBCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWBCombatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
    void EquipItem(TSubclassOf<AWBEquipment> NewEquipmentClass);

    void FireWeapon();
    void ReloadWeapon();
    void CancelReload();

    void OnHitEnemy(AActor* HitEnemy, float DamageAmount);

public:
    void FinishUnequip();
    void FinishEquip();
    void FinishReload();

public:
    int32 KillCount = 0;
    int32 SubdueCount = 0;
    int32 WallDestructionCount = 0;

public:
    UPROPERTY(EditAnywhere, Category = "Montage")
    TObjectPtr<UAnimMontage> FireMontage;

    UPROPERTY(EditAnywhere, Category = "Montage")
    TObjectPtr<UAnimMontage> ReloadMontage;

    UPROPERTY(EditAnywhere, Category = "Stats")
    float FireRange = 2000.0f;

protected:
    AWBEquipment* CurrentWeapon;

    UPROPERTY()
    AWBEquipment* PendingWeapon;

    bool bIsReloading;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Equipments/WBEquipment.h"
#include "ItemInventoryComponent.generated.h"

class UWBCombatComponent;

UCLASS()
class WALLBREAKER_API UItemInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
    TArray<FItemData> InventoryItems;

    bool AddItemToInventory(FItemData NewItem);
    float GetTotalWeight() const;
    bool IsWeightLimitExceeded() const;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    float MaxWeightLimit = 80.0f;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<TSubclassOf<AWBEquipment>> defaultItemList;

protected:
    TObjectPtr<class UWBCombatComponent> CombatComponent;
};
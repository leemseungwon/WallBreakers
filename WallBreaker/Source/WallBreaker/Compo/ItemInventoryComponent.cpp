// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemInventoryComponent.h"
#include "Character/WBCharacter.h"
#include "WBCombatComponent.h"

// Sets default values for this component's properties
UItemInventoryComponent::UItemInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UItemInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

    if (!defaultItemList.IsEmpty())
    {
        for (TSubclassOf<AWBEquipment> ItemClass : defaultItemList)
        {
            if (ItemClass)
            {
                AWBEquipment* CDO = ItemClass->GetDefaultObject<AWBEquipment>();
                if (CDO)
                {
                    AddItemToInventory(CDO->ItemInfo);
                }

                if (InventoryItems.Num() == 1)
                {
                    if (CombatComponent == nullptr)
                    {
                        AWBCharacter* OwnerCharacter = Cast<AWBCharacter>(GetOwner());
                        if (OwnerCharacter)
                        {
                            CombatComponent = OwnerCharacter->GetComponentByClass<UWBCombatComponent>();
                        }
                    }

                    if (CombatComponent)
                    {
                        CombatComponent->EquipItem(ItemClass);
                    }
                }
            }
        }
    }
}


// Called every frame
void UItemInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UItemInventoryComponent::AddItemToInventory(FItemData NewItem)
{
     int32 CurrentOwnedCount = 0;
     for (const FItemData& Item : InventoryItems)
     {
         if (Item.ItemName == NewItem.ItemName)
         {
             CurrentOwnedCount++;
         }
     }
 
     if (CurrentOwnedCount >= NewItem.MaxCount)
     {
         return false;
     }
 
     InventoryItems.Add(NewItem);
     return true;
}

float UItemInventoryComponent::GetTotalWeight() const
{
     float TotalWeight = 0.0f;
     for (const FItemData& Item : InventoryItems)
     {
         TotalWeight += Item.Weight;
     }
     return TotalWeight;
}

bool UItemInventoryComponent::IsWeightLimitExceeded() const
{
    return GetTotalWeight() > MaxWeightLimit;
}
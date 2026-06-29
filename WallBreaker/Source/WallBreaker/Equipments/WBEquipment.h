// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "Enum/ItemType.h"
#include "WBEquipment.generated.h"

class UTexture2D;

USTRUCT()
struct FItemData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EItemType ItemType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Damage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxAmmo;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AddedHP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Price;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Weight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UTexture2D> ItemIcon;
};

UCLASS()
class WALLBREAKER_API AWBEquipment : public AActor
{
	GENERATED_BODY()

public:
    AWBEquipment();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

public:
    UFUNCTION(BlueprintCallable, Category = "Item")
    virtual void UseEquipment();

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    TObjectPtr<class USkeletalMeshComponent> WeaponMesh;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
    FItemData ItemInfo;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item State")
    int32 CurrentItemCount;

};

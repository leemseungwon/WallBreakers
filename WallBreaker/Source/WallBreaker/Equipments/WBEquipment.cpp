// Fill out your copyright notice in the Description page of Project Settings.


#include "WBEquipment.h"

// Sets default values
AWBEquipment::AWBEquipment()
{
    PrimaryActorTick.bCanEverTick = false;

    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
    RootComponent = WeaponMesh;
}

void AWBEquipment::BeginPlay()
{
    Super::BeginPlay();

    if (ItemInfo.ItemType == EItemType::MainWeapon)
    {
        CurrentItemCount = ItemInfo.MaxAmmo;
    }
    else
    {
        CurrentItemCount = 1;
    }
}

void AWBEquipment::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AWBEquipment::UseEquipment()
{

}
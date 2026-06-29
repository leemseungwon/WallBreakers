// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemType.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
    None        UMETA(DisplayName = "None"),
    MainWeapon      UMETA(DisplayName = "MainWeapon"),
    UsableItem     UMETA(DisplayName = "UsableItem")
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WBPlayerHUDWidget.generated.h"

class UTextBlock;
class UProgressBar;
class UImage;
class UTexture2D;

struct FItemData;

UCLASS()
class WALLBREAKER_API UWBPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
    TObjectPtr<UImage> WeaponImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
    TObjectPtr<UTextBlock> AmmoText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
    TObjectPtr<UProgressBar> AmmoProgressBar;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
    TObjectPtr<UProgressBar> HPProgressBar;

public:
    void UpdateEquipWeaponWidget(FItemData ItemData);
    void UpdateAmmoWidget(int CurrentAmmo, int MaxAmmo);
    void UpdateHP(float CurrentHP, float MaxHP);
};

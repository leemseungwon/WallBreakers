// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WBPlayerHUDWidget.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"
#include "Equipments/WBEquipment.h"

void UWBPlayerHUDWidget::UpdateEquipWeaponWidget(FItemData ItemData)
{
    if (WeaponImage && ItemData.ItemIcon)
    {
        WeaponImage->SetBrushFromTexture(ItemData.ItemIcon);
    }
}

void UWBPlayerHUDWidget::UpdateAmmoWidget(int CurrentAmmo, int MaxAmmo)
{
    if (AmmoProgressBar && MaxAmmo > 0)
    {
        FString AmmoString = FString::Printf(TEXT("%d / %d"), CurrentAmmo, MaxAmmo);
        AmmoText->SetText(FText::FromString(AmmoString));

        float AmmoPercent = static_cast<float>(CurrentAmmo) / static_cast<float>(MaxAmmo);
        AmmoProgressBar->SetPercent(AmmoPercent);
    }
}

void UWBPlayerHUDWidget::UpdateHP(float CurrentHP, float MaxHP)
{
    if (HPProgressBar && MaxHP > 0.0f)
    {
        HPProgressBar->SetPercent(CurrentHP / MaxHP);
    }
}

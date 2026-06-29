// Fill out your copyright notice in the Description page of Project Settings.


#include "WallBreaker/GameMode/WBGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Widget/WBResultWidget.h"

void AWBGameMode::OnBombDefused()
{
    int32 FinalScore = CalculateFinalScore(true);
    DisplayResultUI(FinalScore, true);
}

void AWBGameMode::OnPlayerDied()
{
    DisplayResultUI(0, false);
}

int32 AWBGameMode::CalculateFinalScore(bool bIsSuccess)
{
    if (!bIsSuccess) return 0;

    int32 Score = 0;

    Score += 75;
    Score += (15 * KilledTerrorists);

    // if (Hostage)
    // {
    //     float HostageHP = 100.0f;
    //     float HostageMaxHP = 100.0f;
    //     Score += FMath::RoundToInt(20.0f + (50.0f * (HostageHP / HostageMaxHP)));
    // }

    if (CurrentStageTime <= LimitTime)
    {
        Score += 20;
    }
    else
    {
        Score -= 15;
    }

    return FMath::Max(0, Score);
}

void AWBGameMode::DisplayResultUI(int32 Score, bool bIsSuccess)
{
    if (!ResultWidgetClass) return;

    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PC) return;

    UWBResultWidget* ResultWidget = CreateWidget<UWBResultWidget>(PC, ResultWidgetClass);
    if (ResultWidget)
    {
        ResultWidget->SetupResultDisplay(Score, bIsSuccess);
        ResultWidget->AddToViewport();

        FInputModeUIOnly InputMode;
        InputMode.SetWidgetToFocus(ResultWidget->TakeWidget());
        InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

        PC->SetInputMode(InputMode);
        PC->bShowMouseCursor = true;

        UGameplayStatics::SetGamePaused(GetWorld(), true);
    }
}
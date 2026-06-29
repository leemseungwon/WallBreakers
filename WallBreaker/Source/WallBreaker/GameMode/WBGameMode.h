// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WBGameMode.generated.h"

class UWBResultWidget;

UCLASS()
class WALLBREAKER_API AWBGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    int32 KilledTerrorists = 0;
    float CurrentStageTime = 0.0f;
    float LimitTime = 120.0f;

    void OnBombDefused();
    void OnPlayerDied();

protected:
    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UWBResultWidget> ResultWidgetClass;

private:
    int32 CalculateFinalScore(bool bIsSuccess);
    void DisplayResultUI(int32 Score, bool bIsSuccess);
};

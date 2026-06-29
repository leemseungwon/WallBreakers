// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "WBResultWidget.generated.h"

/**
 * 
 */
UCLASS()
class WALLBREAKER_API UWBResultWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* TXT_ResultStatus;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TXT_FinalScore;

    UPROPERTY(meta = (BindWidget))
    UButton* BTN_Restart;

    virtual void NativeConstruct() override;

    UFUNCTION()
    void OnRestartButtonClicked();

public:
    void SetupResultDisplay(int32 Score, bool bIsSuccess);
};

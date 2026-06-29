// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WBResultWidget.h"
#include "Kismet/GameplayStatics.h"

void UWBResultWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (BTN_Restart)
    {
        BTN_Restart->OnClicked.AddDynamic(this, &UWBResultWidget::OnRestartButtonClicked);
    }
}

void UWBResultWidget::SetupResultDisplay(int32 Score, bool bIsSuccess)
{
    if (TXT_ResultStatus)
    {
        FText StatusText = bIsSuccess ? FText::FromString(TEXT("진압 성공!")) : FText::FromString(TEXT("작전 실패..."));
        TXT_ResultStatus->SetText(StatusText);
    }

    if (TXT_FinalScore)
    {
        TXT_FinalScore->SetText(FText::AsNumber(Score));
    }
}

void UWBResultWidget::OnRestartButtonClicked()
{
    if (UWorld* World = GetWorld())
    {
        UGameplayStatics::SetGamePaused(World, false);

        FName CurrentLevelName = FName(*UGameplayStatics::GetCurrentLevelName(World));

        UGameplayStatics::OpenLevel(World, CurrentLevelName);

        APlayerController* PC = GetOwningPlayer();
        if (PC)
        {
            UKismetSystemLibrary::QuitGame(
                GetWorld(),
                PC,
                EQuitPreference::Quit,
                false
            );
        }
    }
}

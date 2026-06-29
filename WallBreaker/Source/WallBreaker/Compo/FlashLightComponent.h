// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FlashLightComponent.generated.h"


UCLASS()
class WALLBREAKER_API UFlashLightComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFlashLightComponent();

    void ToggleFlashlight();

protected:
    virtual void BeginPlay() override;

    UPROPERTY()
    class USpotLightComponent* Flashlight;

    UPROPERTY(EditAnywhere, Category = Flashlight)
    float Intensity = 5000.f;
		
};

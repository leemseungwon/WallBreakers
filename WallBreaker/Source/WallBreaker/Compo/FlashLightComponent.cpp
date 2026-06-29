// Fill out your copyright notice in the Description page of Project Settings.


#include "Compo/FlashLightComponent.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UFlashLightComponent::UFlashLightComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UFlashLightComponent::BeginPlay()
{
    Super::BeginPlay();

    Flashlight = NewObject<USpotLightComponent>(GetOwner());
    Flashlight->RegisterComponent();
    Flashlight->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

    Flashlight->SetRelativeLocation(FVector(0, 0, 50));
    Flashlight->SetIntensity(Intensity);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "WBRoofTrigger.h"
#include "Components/BoxComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/GameplayStatics.h"

AWBRoofTrigger::AWBRoofTrigger()
{
    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));

    RootComponent = TriggerBox;

    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AWBRoofTrigger::OnOverlapBegin);
    TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AWBRoofTrigger::OnOverlapEnd);
}

void AWBRoofTrigger::BeginPlay()
{
    Super::BeginPlay();

    MeshCompo = TargetRoof->FindComponentByClass<UStaticMeshComponent>();
    SetRoofOpacity(0.0f);
}

void AWBRoofTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor->ActorHasTag("Player"))
    {
        if (bIsDisablableRoof)
        {
            SetRoofOpacity(0.0f);
        }
    }
    else if (OtherActor->ActorHasTag("IsHidable"))
    {
        OtherActor->SetActorHiddenInGame(false);

        TArray<UPrimitiveComponent*> PrimitiveComps;
        OtherActor->GetComponents<UPrimitiveComponent>(PrimitiveComps);
        for (UPrimitiveComponent* Comp : PrimitiveComps)
        {
            Comp->SetVisibility(true, true);
        }
    }
}

void AWBRoofTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor->ActorHasTag("Player"))
    {
        if (bIsDisablableRoof)
        {
            SetRoofOpacity(10.0f);
        }
    }
    else if (OtherActor->ActorHasTag("IsHidable"))
    {
        OtherActor->SetActorHiddenInGame(false);

        TArray<UPrimitiveComponent*> PrimitiveComps;
        OtherActor->GetComponents<UPrimitiveComponent>(PrimitiveComps);
        for (UPrimitiveComponent* Comp : PrimitiveComps)
        {
            Comp->SetVisibility(true, true);
        }
    }
}

void AWBRoofTrigger::SetRoofOpacity(float TargetValue)
{
    if (!TargetRoof) 
        return;

    if (!MeshCompo)
        return;

    UMaterialInstanceDynamic* DynMat = Cast<UMaterialInstanceDynamic>(MeshCompo->GetMaterial(0));
    if (!DynMat) 
        DynMat = MeshCompo->CreateDynamicMaterialInstance(0);
    if (DynMat) 
        DynMat->SetScalarParameterValue(FName("OpacityValue"), TargetValue);

    if (TargetValue < 0.1f)
    {
        MeshCompo->SetCollisionProfileName(EnableCollisionProfile);
        ToggleFurnitureVisibility(true);
    }
    else
    {
        MeshCompo->SetCollisionProfileName(DisableCollisionProfile);
        ToggleFurnitureVisibility(false);
    }
}

void AWBRoofTrigger::ToggleFurnitureVisibility(bool bIsVisible)
{
    TArray<AActor*> OverlappingActors;
    TriggerBox->GetOverlappingActors(OverlappingActors);

    for (AActor* Actor : OverlappingActors)
    {
        if (!Actor) continue;

        if (Actor->ActorHasTag("IsHidable"))
        {
            Actor->SetActorHiddenInGame(!bIsVisible);

            TArray<UPrimitiveComponent*> PrimitiveComps;
            Actor->GetComponents<UPrimitiveComponent>(PrimitiveComps);
            for (UPrimitiveComponent* Comp : PrimitiveComps)
            {
                Comp->SetVisibility(bIsVisible, true);
            }
        }
    }
}
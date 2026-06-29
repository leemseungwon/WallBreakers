// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "WBRoofTrigger.generated.h"

UCLASS()
class WALLBREAKER_API AWBRoofTrigger : public AActor
{
    GENERATED_BODY()

public:
    AWBRoofTrigger();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
        int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    void SetRoofOpacity(float TargetValue);

    void ToggleFurnitureVisibility(bool bIsVisible);

protected:
    UPROPERTY(EditAnywhere, Category = "Roof")
    TObjectPtr<class AActor> TargetRoof;

    UPROPERTY(VisibleAnywhere, Category = "Roof")
    TObjectPtr<class UBoxComponent> TriggerBox;

    UPROPERTY(VisibleAnywhere, Category = "Roof")
    TObjectPtr<class UStaticMeshComponent> MeshCompo;

public:
    UPROPERTY(EditAnywhere, Category = "Roof")
    bool bIsDisablableRoof = true;

protected:
    const FName EnableCollisionProfile = TEXT("EnableRoof");
    const FName DisableCollisionProfile = TEXT("DisableRoof");
    const FName FurnitureTag = TEXT("Furniture");
};
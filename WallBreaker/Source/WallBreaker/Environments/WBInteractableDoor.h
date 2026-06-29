// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/WBInteractableInterface.h"
#include "WBInteractableDoor.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class LightComponent;

UCLASS()
class WALLBREAKER_API AWBInteractableDoor : public AActor, public IWBInteractableInterface
{
	GENERATED_BODY()

public:
	AWBInteractableDoor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void OnInteract_Implementation(AActor* Interactor) override;
	virtual void OnEndInteract_Implementation(AActor* Interactor) override;
	virtual FString GetInteractionWidgetText_Implementation() const override;

protected:
	void ToggleHidableVisibility(bool bIsVisible);
	void InitializeHidableActors();

	bool CheckPlayerInside();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> DoorFrameMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> DoorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBoxComponent> TriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsOpened;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> CachedHiddenActors;

	UPROPERTY()
	TArray<TObjectPtr<ULightComponent>> CachedLightComponents;
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/WBInteractableInterface.h"
#include "WBBomb.generated.h"

UCLASS()
class WALLBREAKER_API AWBBomb : public AActor, public IWBInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWBBomb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void OnInteract_Implementation(AActor* Interactor) override;
	virtual void OnEndInteract_Implementation(AActor* Interactor) override;
	virtual FString GetInteractionWidgetText_Implementation() const override;

protected:
	void OnDefuseComplete();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float MaxDefuseTime = 3.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Interaction")
	float CurrentDefuseTime = 0.0f;

	bool bIsDefusing = false;
};

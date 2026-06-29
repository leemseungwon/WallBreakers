// Fill out your copyright notice in the Description page of Project Settings.


#include "Environments/WBBomb.h"
#include "GameMode/WBGameMode.h"

// Sets default values
AWBBomb::AWBBomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BombMesh"));
	RootComponent = Mesh;
    Mesh->SetCanEverAffectNavigation(false);
}

// Called when the game starts or when spawned
void AWBBomb::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWBBomb::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsDefusing)
    {
        CurrentDefuseTime += DeltaTime;

        if (CurrentDefuseTime >= MaxDefuseTime)
        {
            CurrentDefuseTime = MaxDefuseTime;
            OnDefuseComplete();
        }
    }
}

void AWBBomb::OnInteract_Implementation(AActor* Interactor)
{
    bIsDefusing = true;
}

void AWBBomb::OnEndInteract_Implementation(AActor* Interactor)
{
    bIsDefusing = false;
    CurrentDefuseTime = 0.0f;
}

FString AWBBomb::GetInteractionWidgetText_Implementation() const
{
    if (bIsDefusing)
    {
        int32 Percent = FMath::Clamp(FMath::RoundToInt((CurrentDefuseTime / MaxDefuseTime) * 100.0f), 0, 100);
        return FString::Printf(TEXT("해체 중... (%d%%)"), Percent);
    }

    return FString(TEXT("보유한 키를 꾹 눌러 해체"));
}

void AWBBomb::OnDefuseComplete()
{
    bIsDefusing = false;

    AWBGameMode* GameMode = Cast<AWBGameMode>(GetWorld()->GetAuthGameMode());
    if (GameMode)
    {
        GameMode->OnBombDefused();
    }
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "WBInteractableDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "Components/LightComponent.h"

AWBInteractableDoor::AWBInteractableDoor()
{
	PrimaryActorTick.bCanEverTick = false;

	DoorFrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameMesh"));
	RootComponent = DoorFrameMesh;
	DoorFrameMesh->SetCanEverAffectNavigation(false);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);
	DoorMesh->SetCanEverAffectNavigation(false);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);

	TriggerBox->SetGenerateOverlapEvents(true);
	TriggerBox->SetCollisionProfileName(TEXT("Trigger"));

	bIsOpened = false;
}

void AWBInteractableDoor::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle InitTimerHandle;
	GetWorldTimerManager().SetTimer(InitTimerHandle, this, &AWBInteractableDoor::InitializeHidableActors, 0.1f, false);
}

void AWBInteractableDoor::InitializeHidableActors()
{
	TArray<AActor*> OverlappingActors;
	TriggerBox->GetOverlappingActors(OverlappingActors);

	CachedHiddenActors.Empty();

	for (AActor* Actor : OverlappingActors)
	{
		if (!Actor)
			continue;

		if (Actor->ActorHasTag(TEXT("IsHidableFromDoor")))
		{
			CachedHiddenActors.Add(Actor);
			continue;
		}

		TArray<ULightComponent*> LightComps;
		Actor->GetComponents<ULightComponent>(LightComps);
		for (ULightComponent* LightComp : LightComps)
		{
			if (LightComp && LightComp->ComponentHasTag(TEXT("IsHidableFromDoor")))
			{
				CachedHiddenActors.Add(Actor);
				break;
			}
		}
	}

	ToggleHidableVisibility(bIsOpened);
}

void AWBInteractableDoor::OnInteract_Implementation(AActor* Interactor)
{
	bIsOpened = !bIsOpened;

	if (bIsOpened)
	{
		DoorMesh->SetRelativeRotation(FRotator(0.f, 90.f, 0.f));
		ToggleHidableVisibility(true);
	}
	else
	{
		DoorMesh->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
		if (!CheckPlayerInside())
		{
			ToggleHidableVisibility(false);
		}
	}
}

void AWBInteractableDoor::OnEndInteract_Implementation(AActor* Interactor) {}

bool AWBInteractableDoor::CheckPlayerInside()
{
	TArray<AActor*> OverlappingActors;
	TriggerBox->GetOverlappingActors(OverlappingActors);

	for (AActor* Actor : OverlappingActors)
	{
		if (Actor && Actor->ActorHasTag("Player"))
		{
			return true;
		}
	}

	return false;
}

FString AWBInteractableDoor::GetInteractionWidgetText_Implementation() const
{
	return bIsOpened ? TEXT("문 닫기") : TEXT("문 열기");
}

void AWBInteractableDoor::ToggleHidableVisibility(bool bIsVisible)
{
	for (AActor* Actor : CachedHiddenActors)
	{
		if (!Actor)
			continue;

		TArray<ULightComponent*> LightComps;
		Actor->GetComponents<ULightComponent>(LightComps);

		bool bHasToggledLight = false;
		for (ULightComponent* LightComp : LightComps)
		{
			if (LightComp && LightComp->ComponentHasTag(TEXT("IsHidableFromDoor")))
			{
				LightComp->SetVisibility(bIsVisible, true);

				LightComp->SetCastShadows(bIsVisible);

				if (!bIsVisible)
				{
					LightComp->SetIntensity(0.f);
				}
				else
				{
					LightComp->SetIntensity(500.f);
				}

				bHasToggledLight = true;
			}
		}

		if (bHasToggledLight)
		{
			continue;
		}

		Actor->SetActorHiddenInGame(!bIsVisible);

		ACharacter* TargetChar = Cast<ACharacter>(Actor);
		if (TargetChar)
		{
			UCharacterMovementComponent* MovementComp = TargetChar->GetCharacterMovement();
			if (MovementComp)
			{
				if (bIsVisible)	   
					MovementComp->SetMovementMode(MOVE_Walking);
				else               
					MovementComp->DisableMovement();
			}
		}
		else
		{
			TArray<UPrimitiveComponent*> PrimitiveComps;
			Actor->GetComponents<UPrimitiveComponent>(PrimitiveComps);
			for (UPrimitiveComponent* Comp : PrimitiveComps)
			{
				if (Comp)
				{
					Comp->SetVisibility(bIsVisible, true);
				}
			}
		}
	}
}
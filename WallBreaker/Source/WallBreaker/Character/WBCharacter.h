// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "WBCharacter.generated.h"

class UWBCombatComponent;
class UItemInventoryComponent;
class UFlashLightComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UAnimMontage;
class UCameraShakeBase;
class UWBPlayerHUDWidget;
struct FInputActionValue;

UCLASS()
class WALLBREAKER_API AWBCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWBCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyControllerChanged() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

public:
	void PlayActionMontage(UAnimMontage* Montage);

protected:
	void FindBestInteractable();

	void InputInteract();
	void InputEndInteract();

	AActor* InteractingActor; 

public:
	void Die();
	bool IsDeath() const { return bIsDead; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float NormalSpeed = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float InterpSpeed = 20.f;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float CameraRotationSpeed = 100.f;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> Camera;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UWBStateComponent> StateComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UWBCombatComponent> CombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UItemInventoryComponent> ItemInventoryComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UFlashLightComponent> FlashComponent;

#pragma region InputSystem
public:
	void InputMove();
	void InputFire();
	void InputReload();
	void InputRotateCamera(const FInputActionValue& Value);

protected:
	UPROPERTY(EditAnywhere, Category = InputSystem)
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, Category = InputSystem)
	TObjectPtr<class UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = InputSystem)
	TObjectPtr<class UInputAction> RotateCameraAction;

	UPROPERTY(EditAnywhere, Category = InputSystem)
	TObjectPtr<class UInputAction> InteractAction;

	UPROPERTY(EditAnywhere, Category = InputSystem)
	TObjectPtr<class UInputAction> FireAction;

	UPROPERTY(EditAnywhere, Category = InputSystem)
	TObjectPtr<class UInputAction> ReloadAction;

#pragma endregion

protected:
	UPROPERTY(BlueprintReadOnly, Category = Animation)
    float NormalizedTurnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float InteractionRange = 250.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Interaction")
	AActor* TargetInteractableActor;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UWBPlayerHUDWidget> HUDWidgetClass;

	UPROPERTY()
	TObjectPtr<UWBPlayerHUDWidget> HUDWidgetInstance;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float MaxHP = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats)
	float CurrentHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	TSubclassOf<UCameraShakeBase> HitCameraShakeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Montage)
	TObjectPtr<UAnimMontage> HitReactMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Montage)
	TObjectPtr<UAnimMontage> DeathMontage;

	UPROPERTY(BlueprintReadOnly, Category = Stats)
	bool bIsDead = false;

protected:
	UPROPERTY()
	AActor* LastHitRoof;

protected:
	float CurrentCameraYaw;
	float PreviousYaw;

protected:
	const FName EnableRoofProfile = TEXT("EnableRoof");
};

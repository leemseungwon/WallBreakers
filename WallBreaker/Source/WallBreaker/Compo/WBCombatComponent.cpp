// Fill out your copyright notice in the Description page of Project Settings.


#include "WBCombatComponent.h"
#include "DrawDebugHelpers.h"
#include <Kismet/GameplayStatics.h>
#include "Character/WBCharacter.h"
#include "Equipments/WBEquipment.h"
#include "WallBreaker/Widget/WBPlayerHUDWidget.h"

// Sets default values for this component's properties
UWBCombatComponent::UWBCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWBCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UWBCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWBCombatComponent::EquipItem(TSubclassOf<AWBEquipment> NewEquipmentClass)
{
    if (!NewEquipmentClass)
        return;

    AWBCharacter* OwnerCharacter = Cast<AWBCharacter>(GetOwner());
    if (!OwnerCharacter)
        return;

    if (CurrentWeapon)
    {
        CurrentWeapon->Destroy();
    }

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = OwnerCharacter;
    SpawnParams.Instigator = OwnerCharacter;

    CurrentWeapon = GetWorld()->SpawnActor<AWBEquipment>(NewEquipmentClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);

    FItemData itemInfo = CurrentWeapon->ItemInfo;
    if (CurrentWeapon && itemInfo.ItemType == EItemType::MainWeapon)
    {
        FName WeaponSocketName = TEXT("WeaponSocket");

        CurrentWeapon->AttachToComponent(
            OwnerCharacter->GetMesh(),
            FAttachmentTransformRules::SnapToTargetNotIncludingScale,
            WeaponSocketName
        );
    }

    if (OwnerCharacter->HUDWidgetInstance)
    {
        OwnerCharacter->HUDWidgetInstance->UpdateEquipWeaponWidget(itemInfo);
    }
}

void UWBCombatComponent::FireWeapon()
{
    if (bIsReloading) 
        return;

    if (CurrentWeapon && CurrentWeapon->CurrentItemCount > 0)
    {
        CurrentWeapon->CurrentItemCount--;
        CurrentWeapon->UseEquipment();

        AWBCharacter* OwnerCharacter = Cast<AWBCharacter>(GetOwner());
        if (!OwnerCharacter) 
            return;

        if (FireMontage)
        {
            OwnerCharacter->PlayActionMontage(FireMontage);
        }

        FVector StartLoc = GetOwner()->GetActorLocation();
        FVector ForwardVector = GetOwner()->GetActorForwardVector();
        FVector EndLoc = StartLoc + (ForwardVector * FireRange);

        FHitResult HitResult;
        FCollisionQueryParams CollisionParams;
        CollisionParams.AddIgnoredActor(OwnerCharacter);

        bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLoc, EndLoc, ECC_Visibility, CollisionParams);

        DrawDebugLine(GetWorld(), StartLoc, bHit ? HitResult.ImpactPoint : EndLoc, FColor::Red, false, 1.0f, 0, 2.0f);

        if (bHit)
        {
            AActor* HitActor = HitResult.GetActor();
            if (HitActor)
            {
                // 4. 데미지 적용
                OnHitEnemy(HitActor, CurrentWeapon->ItemInfo.Damage);
            }
        }

        if (OwnerCharacter->HUDWidgetInstance)
        {
            OwnerCharacter->HUDWidgetInstance->UpdateAmmoWidget(CurrentWeapon->CurrentItemCount, CurrentWeapon->ItemInfo.MaxAmmo);
        }
    }
    else
    {
        ReloadWeapon();
    }
}

void UWBCombatComponent::ReloadWeapon()
{
    if (bIsReloading || !CurrentWeapon) return;
    if (CurrentWeapon->CurrentItemCount >= CurrentWeapon->ItemInfo.MaxAmmo) return;

    AWBCharacter* OwnerCharacter = Cast<AWBCharacter>(GetOwner());
    if (!OwnerCharacter) return;

    // 장전 상태 활성화
    bIsReloading = true;

    // 장전 몽타주 재생
    if (ReloadMontage)
    {
        OwnerCharacter->PlayActionMontage(ReloadMontage);
    }
    else
    {
        FinishReload();
    }
}

void UWBCombatComponent::FinishReload()
{
    if (!bIsReloading || !CurrentWeapon) 
        return;

    CurrentWeapon->CurrentItemCount = CurrentWeapon->ItemInfo.MaxAmmo;
    bIsReloading = false;

    AWBCharacter* OwnerCharacter = Cast<AWBCharacter>(GetOwner());
    if (!OwnerCharacter)
        return;

    if (OwnerCharacter->HUDWidgetInstance)
    {
        OwnerCharacter->HUDWidgetInstance->UpdateAmmoWidget(CurrentWeapon->CurrentItemCount, CurrentWeapon->CurrentItemCount);
    }
}

void UWBCombatComponent::CancelReload()
{
    if (!bIsReloading || !CurrentWeapon)
        return;

    AWBCharacter* OwnerCharacter = Cast<AWBCharacter>(GetOwner());
    if (OwnerCharacter && OwnerCharacter->GetMesh() && OwnerCharacter->GetMesh()->GetAnimInstance())
    {
        OwnerCharacter->GetMesh()->GetAnimInstance()->Montage_Stop(0.2f, ReloadMontage);
    }

    bIsReloading = false;
}

void UWBCombatComponent::OnHitEnemy(AActor* HitEnemy, float DamageAmount)
{
    if (!HitEnemy)
        return;

    AWBCharacter* OwnerCharacter = Cast<AWBCharacter>(GetOwner());
    AController* InstigatorController = OwnerCharacter ? OwnerCharacter->GetController() : nullptr;

    UGameplayStatics::ApplyDamage(
        HitEnemy,
        DamageAmount,
        InstigatorController,
        OwnerCharacter,
        UDamageType::StaticClass()
    );
}
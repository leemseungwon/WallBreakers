// Fill out your copyright notice in the Description page of Project Settings.


#include "Behavior Tree/Enemy/WBBTService_DetectPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "Character/WBEnemy.h"
#include "WallBreaker/Character/WBCharacter.h"
#include "Engine/Engine.h"

UWBBTService_DetectPlayer::UWBBTService_DetectPlayer()
{
	NodeName = TEXT("Detect & Range Lock Player");

	// 감지 연산 최적화를 위해 0.4초 주기로 갱신합니다.
	Interval = 0.4f;
	RandomDeviation = 0.05f;
}

void UWBBTService_DetectPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController) return;

	AWBEnemy* Enemy = Cast<AWBEnemy>(AIController->GetPawn());
	if (!Enemy || Enemy->IsDead()) return;

	UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent();
	if (!BBComp) return;

	AWBCharacter* Player = Cast<AWBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (!Player || Player->IsDeath())
	{
		BBComp->ClearValue(GetSelectedBlackboardKey());
		return;
	}

	FVector EnemyLoc = Enemy->GetActorLocation();
	FVector PlayerLoc = Player->GetActorLocation();
	FVector SpawnLoc = Enemy->GetSpawnLocation();

	// 1. 높이(Z축) 편차 절대값 검사 (층간 단차가 2.5m 이상 벌어지면 타깃 상실)
	const float MaxDetectionHeightDifference = 250.0f;
	float HeightDifference = FMath::Abs(EnemyLoc.Z - PlayerLoc.Z);

	AActor* CurrentTarget = Cast<AActor>(BBComp->GetValueAsObject(GetSelectedBlackboardKey()));

	if (HeightDifference > MaxDetectionHeightDifference)
	{
		if (CurrentTarget != nullptr)
		{
			BBComp->ClearValue(GetSelectedBlackboardKey());
		}
		return;
	}

	// 2. 수평 평면(X-Y) 상의 정밀 2D 거리 계산
	float DistToPlayer = FVector2D::Distance(FVector2D(EnemyLoc.X, EnemyLoc.Y), FVector2D(PlayerLoc.X, PlayerLoc.Y));
	float DistFromSpawn = FVector2D::Distance(FVector2D(SpawnLoc.X, SpawnLoc.Y), FVector2D(EnemyLoc.X, EnemyLoc.Y));

	if (CurrentTarget == nullptr)
	{
		// [대기/정찰 상태] -> 최초 인지할 때만 라인 트레이스로 벽 유무(시야각 정렬)를 검사합니다.
		if (DistToPlayer <= Enemy->DetectRange)
		{
			FHitResult ObstacleHit;
			FCollisionQueryParams VisualParams;
			VisualParams.AddIgnoredActor(Enemy);
			VisualParams.AddIgnoredActor(Player);

			// 레이 시작/끝 높이를 허리선(50)으로 보정하여 바닥 걸림 방지
			FVector TraceStart = EnemyLoc + FVector(0.0f, 0.0f, 50.0f);
			FVector TraceEnd = PlayerLoc + FVector(0.0f, 0.0f, 50.0f);

			bool bWallBlocking = GetWorld()->LineTraceSingleByChannel(
				ObstacleHit,
				TraceStart,
				TraceEnd,
				ECC_Visibility,
				VisualParams
			);

			// 벽에 완전히 가려져 있지 않은 상태의 플레이어만 최초 감지 대상으로 락온합니다.
			if (!bWallBlocking)
			{
				BBComp->SetValueAsObject(GetSelectedBlackboardKey(), Player);
			}
		}
	}
	else
	{
		// [추격/교전 상태] -> 벽 유무를 실시간으로 판단해 타깃을 지우지 않습니다!
		// 오직 추격 한계 거리를 벗어났을 때만 타깃을 해제하여, 벽 뒤로 숨더라도 끝까지 코너를 돌아 쫓아가게 유도합니다.
		if (DistToPlayer > Enemy->LoseRange || DistFromSpawn > Enemy->MaxChaseDistanceFromSpawn)
		{
			BBComp->ClearValue(GetSelectedBlackboardKey());
		}
	}
}
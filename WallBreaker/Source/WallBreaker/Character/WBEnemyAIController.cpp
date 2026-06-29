// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WBEnemyAIController.h"
#include "Character/WBEnemy.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

AWBEnemyAIController::AWBEnemyAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AWBEnemyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 블랙보드 컴포넌트 가져오기
    UBlackboardComponent* BlackboardComp = GetBlackboardComponent();
    if (!BlackboardComp) return;

    // 블랙보드에서 TargetActor를 Object로 가져오기
    UObject* TargetObj = BlackboardComp->GetValueAsObject(TEXT("TargetActor"));
    AActor* TargetActor = Cast<AActor>(TargetObj);

    if (TargetActor)
    {
        // 타겟의 위치 가져오기
        FVector TargetLocation = TargetActor->GetActorLocation();

        // 블랙보드에 위치(Vector) 저장
        BlackboardComp->SetValueAsVector(TEXT("MoveToLocation"), TargetLocation);

        // 내비게이션 시스템을 통해 이동 가능한 위치로 투영 (ProjectPointToNavigation)
        UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
        if (NavSys)
        {
            FNavLocation NavLocation;
            // ENavQueryFilter_UseDefault로 호출하는 것이 가장 일반적인 오버로드입니다.
            bool bSuccess = NavSys->ProjectPointToNavigation(
                TargetLocation,
                NavLocation,
                FVector(100.f, 100.f, 200.f) // 탐색 범위
            );

            if (bSuccess)
            {
                // 필요하다면 NavLocation.Location을 추가적인 로직에 활용 가능
            }
        }
    }
}

void AWBEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AWBEnemy* EnemyCharacter = Cast<AWBEnemy>(InPawn);
	if (EnemyCharacter && EnemyCharacter->GetBehaviorTree())
	{
		if (BlackboardComponent->InitializeBlackboard(*(EnemyCharacter->GetBehaviorTree()->BlackboardAsset)))
		{
			BlackboardComponent->SetValueAsObject(TEXT("SelfActor"), EnemyCharacter);
			BlackboardComponent->SetValueAsVector(TEXT("SpawnLocation"), EnemyCharacter->GetSpawnLocation());

			BehaviorTreeComponent->StartTree(*(EnemyCharacter->GetBehaviorTree()));
		}
	}
}
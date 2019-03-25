// Fill out your copyright notice in the Description page of Project Settings.

#include "SelectNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type USelectNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	
	// Get patrol points
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController) { return EBTNodeResult::Failed; }
	UPatrolRoute* PatrolRoute = AIController->GetPawn()->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
	TArray<AActor*> PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) { return EBTNodeResult::Failed; }

	// Set next waypoint
	int32 Index = BlackboardComponent->GetValueAsInt(WaypointIndexKey.SelectedKeyName);
	BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle index
	int32 NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComponent->SetValueAsInt(WaypointIndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "SelectNextWaypoint.generated.h"


/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API USelectNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector WaypointIndexKey;
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector WaypointKey;
};

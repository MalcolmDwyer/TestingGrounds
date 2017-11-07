// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
  auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
  
  if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
  auto PatrolPoints = PatrolRoute->GetPatrolPoints();
  
  if (PatrolPoints.Num() == 0) {
    UE_LOG(LogTemp, Warning, TEXT("%s is missing patrol points"), *ControlledPawn->GetName());
    return EBTNodeResult::Failed;
  }
  
  auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
  auto Index = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
  
  if (!PatrolPoints.Num()) {
    return EBTNodeResult::Succeeded;
  }
  
  AActor * NextWaypoint = PatrolPoints[Index];
  
  if (!ensure(NextWaypoint)) { return EBTNodeResult::Succeeded; }
  
  BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, NextWaypoint);

  int32 NextIndex = (Index + 1)%(PatrolPoints.Num());
  BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
  
  return EBTNodeResult::Succeeded;
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrollingGuard.h"
#include "PatrolRoute.h"



TArray<AActor *> APatrollingGuard::GetPatrolPoints()
{
  return PatrolPoints_CPP;
}
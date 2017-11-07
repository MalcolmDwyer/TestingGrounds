// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

private:
  UPROPERTY(EditInstanceOnly, Category = "PatrolRoute")
  TArray<AActor *> PatrolPoints;

public:
  UFUNCTION(BlueprintCallable, Category = "PatrolRoute")
  TArray<AActor *> GetPatrolPoints() const;
};

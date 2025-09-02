// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointPosition.h"
#include "Pass.generated.h"

UCLASS()
class FIRSTPROJECTPERSO_API APass : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta = (EditLine))
	TArray<APointPosition*> points;

public:	
	APass();
	FORCEINLINE TArray<APointPosition*> GetPoints()const { return points; }

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};

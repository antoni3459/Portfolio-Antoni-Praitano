// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointPosition.generated.h"

UCLASS()
class FIRSTPROJECTPERSO_API APointPosition : public AActor
{
	GENERATED_BODY()
	
public:	
	APointPosition();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};

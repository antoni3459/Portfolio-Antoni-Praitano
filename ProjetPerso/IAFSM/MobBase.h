// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DistanceEnemy.h"
#include "MobBase.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API AMobBase : public ADistanceEnemy
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime)override;
	virtual void EnterDectedBehaviour(AActor* _player)override;
};

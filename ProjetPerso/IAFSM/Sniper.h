// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DistanceEnemy.h"
#include "Sniper.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API ASniper : public ADistanceEnemy
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	virtual void EnterDectedBehaviour(AActor* _player)override;
	virtual void ExitDectedBehaviour(AActor* _player)override;
};

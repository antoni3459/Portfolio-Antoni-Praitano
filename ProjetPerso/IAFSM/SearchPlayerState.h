// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "MoveMobDistance.h"
#include "EndResearchTransition.h"
#include "SearchPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API USearchPlayerState : public UState
{
	GENERATED_BODY()
	
	UPROPERTY()
	TObjectPtr<AMoveMobDistance> mob = nullptr;
	UPROPERTY()
	FRotator initRota;

	UPROPERTY()
	int rota = 1;

	UPROPERTY()
	TObjectPtr<UEndResearchTransition> searchTransition = nullptr;

public:
	virtual void EnterState(UFSMObject* _fsm)override;
	virtual void InitTransition()override;
	virtual void TickState()override;

	void SearchMode();
	virtual void ExitState()override;
 };

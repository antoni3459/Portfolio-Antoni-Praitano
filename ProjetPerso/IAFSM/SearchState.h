// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "MoveMobDistance.h"
#include "SearchState.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API USearchState : public UState
{
	GENERATED_BODY()
	UPROPERTY()
	TObjectPtr<AMoveMobDistance> mob = nullptr;
	UPROPERTY()
	FVector lookAt;

public:
	virtual void EnterState(UFSMObject* _fsm)override;
	virtual void ExitState()override;

};

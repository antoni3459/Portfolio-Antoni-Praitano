// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "UnDetectState.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API UUnDetectState : public UState
{
	GENERATED_BODY()

public:
	virtual void EnterState(UFSMObject* _fsm)override;
};

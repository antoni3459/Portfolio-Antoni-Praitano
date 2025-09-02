// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Transition.h"
#include "IdleTransition.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API UIdleTransition : public UTransition
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	int waitTime = 3;

	UPROPERTY()
	bool isDone = false;

	FTimerHandle timer;

public:
	virtual void InitTransition(UState* _state)override;
	virtual bool IsValidTransition()override;

	void Wait();
};

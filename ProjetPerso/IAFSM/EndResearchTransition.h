// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Transition.h"
#include "EndResearchTransition.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API UEndResearchTransition : public UTransition
{
	GENERATED_BODY()
	UPROPERTY()
	bool isEnd = false;

public:
	virtual void InitTransition(UState* _state)override;
	virtual bool IsValidTransition()override;

	void IsEnd();
};

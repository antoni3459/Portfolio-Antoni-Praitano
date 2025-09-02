// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Transition.h"
#include "IANavigationComponent.h"
#include "WaitPointTransition.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API UWaitPointTransition : public UTransition
{
	GENERATED_BODY()
	UPROPERTY()
	TObjectPtr<UIANavigationComponent> nav = nullptr;
	FVector endPosition;
	
public:
	virtual void InitTransition(UState* _state)override;
	virtual bool IsValidTransition()override;
};

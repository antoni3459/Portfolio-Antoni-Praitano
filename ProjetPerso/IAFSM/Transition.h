// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Transition.generated.h"

/**
 * 
 */
class UState;
UCLASS(Abstract, Blueprintable)
class FIRSTPROJECTPERSO_API UTransition : public UObject
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TSubclassOf<UState> nexState = nullptr;
	UPROPERTY()
	TObjectPtr<UState> currentState = nullptr;
	
public:
	FORCEINLINE TSubclassOf<UState> GetNextState()const { return nexState; }

	virtual void InitTransition(UState* _state);
	virtual bool IsValidTransition();
};

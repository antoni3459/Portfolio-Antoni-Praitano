// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Transition.h"
#include "State.generated.h"

/**
 * 
 */
class UFSMObject;
UCLASS(Abstract,Blueprintable)
class FIRSTPROJECTPERSO_API UState : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UTransition>> transitions;
	UPROPERTY()
	TArray<TObjectPtr<UTransition>> currentTransition;

	UPROPERTY()
	TObjectPtr< UFSMObject> fsm = nullptr;

public:
	FORCEINLINE UFSMObject* GetFSM()const { return fsm; }

	virtual void EnterState(UFSMObject* _fsm);
	virtual void TickState();
	virtual void ExitState();

	virtual void InitTransition();
	void IsValidTransition();
};

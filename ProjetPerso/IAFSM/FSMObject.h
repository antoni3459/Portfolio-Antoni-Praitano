// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "State.h"
#include "FSMObject.generated.h"

/**
 * 
 */
class UFSMComponent;
UCLASS(Abstract,Blueprintable)
class FIRSTPROJECTPERSO_API UFSMObject : public UObject
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UState> startingState = nullptr;
	UPROPERTY()
	TObjectPtr<UState> currentState = nullptr;
	UPROPERTY()
	TObjectPtr<UFSMComponent> owner = nullptr;
public:
	FORCEINLINE UFSMComponent* GetFSMCompoennt()const { return owner; }

	virtual void Start(UFSMComponent* _owner);
	virtual void TickFSM();
	virtual void ExitFSM();

	void SetNextState(TSubclassOf<UState> _nexState);
};

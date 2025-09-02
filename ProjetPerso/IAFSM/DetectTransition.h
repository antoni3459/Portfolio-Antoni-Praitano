// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Transition.h"
#include "DetectPlayer.h"
#include "DetectTransition.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API UDetectTransition : public UTransition
{
	GENERATED_BODY()
	UPROPERTY()
	TObjectPtr<UDetectPlayer> detect = nullptr;

public:
	virtual void InitTransition(UState* _state)override;
	virtual bool IsValidTransition()override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMObject.h"
#include "DetectPlayer.h"
#include "DetectFSM.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API UDetectFSM : public UFSMObject
{
	GENERATED_BODY()
	UPROPERTY()
	TObjectPtr<UDetectPlayer> detectPlayer = nullptr;
	
public:
	FORCEINLINE UDetectPlayer* GetDetectPlayer()const { return detectPlayer; }

	virtual void Start(UFSMComponent* _owner);

};

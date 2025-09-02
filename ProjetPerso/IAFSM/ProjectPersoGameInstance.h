// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ManagerPass.h"
#include "ProjectPersoGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API UProjectPersoGameInstance : public UGameInstance
{
	GENERATED_BODY()
	UPROPERTY()
	TObjectPtr<UManagerPass> currentManager = nullptr;

public:
	virtual void Init()override;

	FORCEINLINE UManagerPass* GetCurrentManager()const { return currentManager; }
};

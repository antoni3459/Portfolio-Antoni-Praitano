// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Pass.h"
#include "PointPosition.h"
#include "ManagerPass.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API UManagerPass : public UObject
{
	GENERATED_BODY()
	UPROPERTY()
	TArray<APass*> allPass;

public:
	FORCEINLINE TArray<APass*> GetAllPass()const { return allPass; }
	FORCEINLINE void AddPass(APass* _pass) { allPass.Add(_pass); }

	FORCEINLINE APointPosition* GetPoint(int _nbrPass, int _nbrPoint) { return allPass[_nbrPass]->GetPoints()[_nbrPoint]; }
};

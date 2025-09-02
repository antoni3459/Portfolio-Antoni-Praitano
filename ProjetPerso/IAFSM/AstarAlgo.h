// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NodeNav.h"
#include "AstarAlgo.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API UAstarAlgo : public UObject
{
	GENERATED_BODY()
	UPROPERTY()
	TArray<UNodeNav*> correctPath;

public:
	FORCEINLINE TArray<UNodeNav*>GetCorrectPath ()const { return correctPath; }
	void ComputePath(UNodeNav* _start, UNodeNav* _end);
	TArray<UNodeNav*> GetFinalPath(UNodeNav* _start, UNodeNav* _end);
	void DrawPath();
};

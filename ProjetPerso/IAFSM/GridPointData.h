// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "GridPointData.generated.h"

/**
 * 
 */
class UNodeNav;
UCLASS()
class FIRSTPROJECTPERSO_API UGridPointData : public UDataAsset
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere, meta = (EditLine))
	TArray< UNodeNav*> nodes;

public:
	FORCEINLINE TArray<UNodeNav*>& GetNodes() { return nodes; }

	void ResetCost();

	UNodeNav* GetCloseNode(FVector _location);
	
};

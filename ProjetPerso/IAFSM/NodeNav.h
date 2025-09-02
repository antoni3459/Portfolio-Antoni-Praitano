// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridPointData.h"
#include "Math/NumericLimits.h"
#include "NodeNav.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FIRSTPROJECTPERSO_API UNodeNav : public UObject
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TObjectPtr< UGridPointData> grid = nullptr;
	UPROPERTY(VisibleAnywhere)
	FVector position;
	UPROPERTY(VisibleAnywhere)
	TArray< int> successors;

	UPROPERTY(VisibleAnywhere)
	bool isSelected = false;
	UPROPERTY(VisibleAnywhere)
	bool isClose = true;

	UPROPERTY(VisibleAnywhere)
	float g = TNumericLimits<float>::Max();
	UPROPERTY(VisibleAnywhere)
	float h = TNumericLimits<float>::Max();

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UNodeNav> parent = nullptr;

	UPROPERTY(EditAnywhere)
	TArray<TEnumAsByte<EObjectTypeQuery>> layers;

public:
	FORCEINLINE float GetF()const { return g + h; }
#pragma region Get_Set
	FORCEINLINE UGridPointData* GetGrid()const { return grid; }
	FORCEINLINE void SetGrid(UGridPointData* _grid) { grid = _grid; }

	FORCEINLINE FVector GetPosition()const { return position; }
	FORCEINLINE void SetPosition(FVector _position) { position = _position; }

	FORCEINLINE TArray<int> GetSuccessors()const { return successors; }

	FORCEINLINE bool GetIsSelected()const { return isSelected; }
	FORCEINLINE void SetIsSelected(bool _value) { isSelected = _value; }

	FORCEINLINE bool GetIsClose()const { return isClose;	}
	FORCEINLINE void SetIsClose(bool _value) { isClose = _value; }

	FORCEINLINE float GetG()const { return g; }
	FORCEINLINE void SetG(float _g) { g = _g; }

	FORCEINLINE float GetH()const { return h; }
	FORCEINLINE void SetH(float _h) { h = _h; }

	FORCEINLINE UNodeNav* GetParent()const { return parent; }
	FORCEINLINE void SetParent(UNodeNav* _parent) { parent = _parent; }
#pragma endregion

	FORCEINLINE void AddSuccessors(int _successor) { successors.Add(_successor); }

public:
	void CheckForObstacle();

	void DrawDebug();

	void ResetNode();
};

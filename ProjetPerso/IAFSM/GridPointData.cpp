// Fill out your copyright notice in the Description page of Project Settings.


#include "GridPointData.h"
#include "NodeNav.h"
#include "Math/NumericLimits.h"

void UGridPointData::ResetCost()
{
	for (size_t i = 0; i < nodes.Num(); i++)
		nodes[i]->ResetNode();
}

UNodeNav* UGridPointData::GetCloseNode(FVector _location)
{
	UNodeNav* _current = nullptr;
	float _max = TNumericLimits<float>::Max();
	for (size_t i = 0; i < nodes.Num(); i++)
	{
		float _dist = FVector::Dist(nodes[i]->GetPosition(), _location);
		if (_dist < _max)
		{
			_max = _dist;
			_current = nodes[i];
		}

	}
	return _current;
}

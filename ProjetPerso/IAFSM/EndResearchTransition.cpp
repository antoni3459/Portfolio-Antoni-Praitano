// Fill out your copyright notice in the Description page of Project Settings.


#include "EndResearchTransition.h"

void UEndResearchTransition::InitTransition(UState* _state)
{
	Super::InitTransition(_state);
}

bool UEndResearchTransition::IsValidTransition()
{
	return isEnd;
}

void UEndResearchTransition::IsEnd()
{
	isEnd = true;
}

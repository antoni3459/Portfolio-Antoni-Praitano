// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleTransition.h"

void UIdleTransition::InitTransition(UState* _state)
{
	Super::InitTransition(_state);
	GetWorld()->GetTimerManager().SetTimer(timer, this, &UIdleTransition::Wait, waitTime);
}

bool UIdleTransition::IsValidTransition()
{
	return isDone;
}

void UIdleTransition::Wait()
{
	isDone = true;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Transition.h"
#include "State.h"

void UTransition::InitTransition(UState* _state)
{
	currentState = _state;
}

bool UTransition::IsValidTransition()
{
	return false;
}

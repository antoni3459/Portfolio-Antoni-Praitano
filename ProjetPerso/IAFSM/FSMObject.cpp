// Fill out your copyright notice in the Description page of Project Settings.


#include "FSMObject.h"
#include "FSMComponent.h"

void UFSMObject::Start(UFSMComponent* _owner)
{
	owner = _owner;
	if (!startingState)
		return;
	currentState = NewObject<UState>(this, startingState);
	currentState->EnterState(this);
}

void UFSMObject::TickFSM()
{
	if (!currentState)
		return;
	currentState->TickState();
}

void UFSMObject::ExitFSM()
{
	if (!currentState)
		return;
	currentState->ExitState();
}

void UFSMObject::SetNextState(TSubclassOf<UState> _nexState)
{
	if (!_nexState)
		return;
	currentState = NewObject<UState>(this, _nexState);
	currentState->EnterState(this);
}

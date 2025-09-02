// Fill out your copyright notice in the Description page of Project Settings.


#include "State.h"
#include "FSMObject.h"
#include "Kismet/KismetSystemLibrary.h"

void UState::EnterState(UFSMObject* _fsm)
{
	fsm = _fsm;
	InitTransition();
}

void UState::TickState()
{
	IsValidTransition();
}

void UState::ExitState()
{
}

void UState::InitTransition()
{
	for (int i = 0; i < transitions.Num(); i++)
	{
		if (!transitions[i])
			return;
		UTransition* _transition = NewObject<UTransition>(this, transitions[i]);
		_transition->InitTransition(this);
		currentTransition.Add(_transition);
	}
}

void UState::IsValidTransition()
{
	for (int i = 0; i < currentTransition.Num(); i++)
	{
		if (currentTransition[i]->IsValidTransition())
		{
			ExitState();
			fsm->SetNextState(currentTransition[i]->GetNextState());
			return;
		}
	}
}

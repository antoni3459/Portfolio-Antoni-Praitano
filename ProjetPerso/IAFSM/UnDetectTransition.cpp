// Fill out your copyright notice in the Description page of Project Settings.


#include "UnDetectTransition.h"
#include "DetectFSM.h"
#include "State.h"


void UUnDetectTransition::InitTransition(UState* _state)
{
	Super::InitTransition(_state);
	UDetectFSM* _fsm = Cast<UDetectFSM>(_state->GetFSM());
	detect = _fsm->GetDetectPlayer();
}

bool UUnDetectTransition::IsValidTransition()
{
	return !detect->Detect();
}

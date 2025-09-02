// Fill out your copyright notice in the Description page of Project Settings.


#include "DetectTransition.h"
#include "State.h"
#include "DetectFSM.h"

void UDetectTransition::InitTransition(UState* _state)
{
	Super::InitTransition(_state);
	UDetectFSM* _fsm = Cast<UDetectFSM>(_state->GetFSM());
	if (!_fsm)
		return;
	detect = _fsm->GetDetectPlayer();
}

bool UDetectTransition::IsValidTransition()
{
	return detect->Detect();
}

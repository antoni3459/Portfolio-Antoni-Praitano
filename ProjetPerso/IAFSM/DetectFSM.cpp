// Fill out your copyright notice in the Description page of Project Settings.


#include "DetectFSM.h"
#include "FSMComponent.h"
#include "MoveMobDistance.h"

void UDetectFSM::Start(UFSMComponent* _owner)
{
	AMoveMobDistance* _mob = Cast< AMoveMobDistance>(_owner->GetOwner());
	detectPlayer = _mob->GetDetect();
	Super::Start(_owner);
}

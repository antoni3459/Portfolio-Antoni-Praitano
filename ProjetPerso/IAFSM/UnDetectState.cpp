// Fill out your copyright notice in the Description page of Project Settings.


#include "UnDetectState.h"
#include "DetectFSM.h"
#include "FSMComponent.h"
#include "IANavigationComponent.h"
#include "MoveMobDistance.h"

void UUnDetectState::EnterState(UFSMObject* _fsm)
{
	Super::EnterState(_fsm);
	UDetectFSM* _detectFsm = Cast<UDetectFSM>(_fsm);
	AMoveMobDistance* _mob = Cast<AMoveMobDistance>(_fsm->GetFSMCompoennt()->GetOwner());
	UIANavigationComponent* _nav = Cast<UIANavigationComponent>(_mob->GetComponentByClass<UIANavigationComponent>());

	_nav->Request(_detectFsm->GetDetectPlayer()->GetTargetLocation());
	_mob->ClearTimerShoot();
}

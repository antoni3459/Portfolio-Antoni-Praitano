// Fill out your copyright notice in the Description page of Project Settings.


#include "DetectState.h"
#include "DetectFSM.h"
#include "FSMComponent.h"
#include "IANavigationComponent.h"
#include "MoveMobDistance.h"

void UDetectState::EnterState(UFSMObject* _fsm)
{
	Super::EnterState(_fsm);
	UDetectFSM* _detectfsm = Cast<UDetectFSM>(_fsm);
	AMoveMobDistance* _mob = Cast<AMoveMobDistance>(_fsm->GetFSMCompoennt()->GetOwner());
	UIANavigationComponent* _nav = Cast<UIANavigationComponent>(_mob->GetComponentByClass<UIANavigationComponent>());

	_mob->TimerShoot();
	_nav->Request(_detectfsm->GetDetectPlayer()->GetPlayer()->GetActorLocation());
	_mob->LookAt(_detectfsm->GetDetectPlayer()->GetPlayer()->GetActorLocation());
}

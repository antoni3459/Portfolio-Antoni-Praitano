// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchState.h"
#include "FSMObject.h"
#include "FSMComponent.h"
#include "IANavigationComponent.h"
#include "ProjectPersoGameInstance.h"

void USearchState::EnterState(UFSMObject* _fsm)
{
	Super::EnterState(_fsm);
	mob = Cast<AMoveMobDistance>(_fsm->GetFSMCompoennt()->GetOwner());
	mob->EndMove();
	UIANavigationComponent* _nav = Cast<UIANavigationComponent>(mob->GetComponentByClass<UIANavigationComponent>());
	_nav->Request(mob->EndMove());
}

void USearchState::ExitState()
{
	Super::ExitState();
	mob->SetCurrentPoint(mob->GetCurrentPoint() + 1);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchPlayerState.h"
#include "MoveMobDistance.h"
#include "FSMObject.h"
#include "FSMComponent.h"
#include "Kismet/KismetSystemLibrary.h"

void USearchPlayerState::EnterState(UFSMObject* _fsm)
{
	Super::EnterState(_fsm);
	mob = Cast<AMoveMobDistance>(_fsm->GetFSMCompoennt()->GetOwner());
	initRota = mob->GetActorRotation();
}

void USearchPlayerState::InitTransition()
{
	Super::InitTransition();
	for (int i = 0; i < currentTransition.Num(); i++)
	{
		UEndResearchTransition* _search = Cast< UEndResearchTransition>(currentTransition[i]);
		if (_search)
		{
			searchTransition = _search;
			return;
		}	
	}
}

void USearchPlayerState::TickState()
{
	Super::TickState();
	SearchMode();
}

void USearchPlayerState::SearchMode()
{
	FRotator _ratotion = FRotator(0, rota, 0);
	mob->SetActorRotation(mob->GetActorRotation() + _ratotion);
	if (initRota.GetNormalized().Equals(mob->GetActorRotation().GetNormalized(),0.5))
		searchTransition->IsEnd();
}

void USearchPlayerState::ExitState()
{
	mob->SetCurrentPoint(mob->GetCurrentPoint()-1);
}

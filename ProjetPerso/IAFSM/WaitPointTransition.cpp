// Fill out your copyright notice in the Description page of Project Settings.


#include "WaitPointTransition.h"
#include "FSMObject.h"
#include "FSMComponent.h"
#include "MoveMobDistance.h"
#include "Kismet/KismetSystemLibrary.h"


void UWaitPointTransition::InitTransition(UState* _state)
{
	Super::InitTransition(_state);
	nav = Cast<UIANavigationComponent>(_state->GetFSM()->GetFSMCompoennt()->GetOwner()->GetComponentByClass<UIANavigationComponent>());
}

bool UWaitPointTransition::IsValidTransition()
{
	return nav->GetIsDestination();
}

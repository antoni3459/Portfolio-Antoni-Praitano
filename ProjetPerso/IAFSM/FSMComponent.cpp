// Fill out your copyright notice in the Description page of Project Settings.


#include "FSMComponent.h"

UFSMComponent::UFSMComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UFSMComponent::BeginPlay()
{
	Super::BeginPlay();
	StartFSM();
}

void UFSMComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	TickFSM();
}

void UFSMComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	CloseFSM();
	Super::EndPlay(EndPlayReason);
}

void UFSMComponent::StartFSM()
{
	if (!fsm)
		return;
	currentFSM = NewObject<UFSMObject>(this, fsm);
	currentFSM->Start(this);
}

void UFSMComponent::TickFSM()
{
	if (!currentFSM)
		return;
	currentFSM->TickFSM();
}

void UFSMComponent::CloseFSM()
{
	if (!currentFSM)
		return;
	currentFSM->ExitFSM();
}


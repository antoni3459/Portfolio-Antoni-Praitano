// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectPersoGameInstance.h"

void UProjectPersoGameInstance::Init()
{
	Super::Init();
	currentManager = NewObject<UManagerPass>(this);
}

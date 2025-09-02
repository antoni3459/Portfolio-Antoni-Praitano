// Fill out your copyright notice in the Description page of Project Settings.


#include "Pass.h"
#include "ProjectPersoGameInstance.h"

APass::APass()
{
	PrimaryActorTick.bCanEverTick = false;

}

void APass::BeginPlay()
{
	Super::BeginPlay();
	UProjectPersoGameInstance* _gi = Cast< UProjectPersoGameInstance>(GetWorld()->GetGameInstance());
	_gi->GetCurrentManager()->AddPass(this);
}

void APass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


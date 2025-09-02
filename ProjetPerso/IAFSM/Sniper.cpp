// Fill out your copyright notice in the Description page of Project Settings.


#include "Sniper.h"

void ASniper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isDected)
		LookAt(player->GetActorLocation());
}

void ASniper::EnterDectedBehaviour(AActor* _player)
{
	GetWorldTimerManager().SetTimer(timerShoot,this,&ASniper::Shoot, timeShoot, true);
}

void ASniper::ExitDectedBehaviour(AActor* _player)
{
	GetWorldTimerManager().ClearTimer(timerShoot);
}



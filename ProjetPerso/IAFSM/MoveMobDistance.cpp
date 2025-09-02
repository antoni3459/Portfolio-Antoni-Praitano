// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveMobDistance.h"
#include "ProjectPersoGameInstance.h"
#include "Pass.h"
#include "Kismet/KismetSystemLibrary.h"

AMoveMobDistance::AMoveMobDistance()
{
	detect = CreateDefaultSubobject<UDetectPlayer>("DetectPlayer");
	AddOwnedComponent(detect);
}

void AMoveMobDistance::BeginPlay()
{
	Super::BeginPlay();
	newPosition = GetActorLocation();
}

void AMoveMobDistance::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);
	Move();
	DrawDebugSphere(GetWorld(), newPosition, 50, 10, FColor::Blue);
	Debug();
}

void AMoveMobDistance::Debug()
{
	DrawDebugSphere(GetWorld(), pointMove, 50, 10, FColor::Black);
}

void AMoveMobDistance::Move()
{
	FVector _newLocation = FMath::VInterpConstantTo(GetActorLocation(), newPosition, GetWorld()->DeltaTimeSeconds, speed);
	SetActorLocation(_newLocation);
}

FVector AMoveMobDistance::EndMove()
{
	UProjectPersoGameInstance* _gi = Cast<UProjectPersoGameInstance>(GetWorld()->GetGameInstance());
	if (currentPoint >= _gi->GetCurrentManager()->GetAllPass()[nbrPass]->GetPoints().Num() || currentPoint<0)
		currentPoint = 0;
	pointMove = _gi->GetCurrentManager()->GetPoint(nbrPass, currentPoint)->GetActorLocation();
	return pointMove;
}

void AMoveMobDistance::TimerShoot()
{
	if(!timerShoot.IsValid())
		GetWorld()->GetTimerManager().SetTimer(timerShoot, this, &AMoveMobDistance::Shoot, timeShoot, true);
}

void AMoveMobDistance::ClearTimerShoot()
{
	GetWorld()->GetTimerManager().ClearTimer(timerShoot);
}



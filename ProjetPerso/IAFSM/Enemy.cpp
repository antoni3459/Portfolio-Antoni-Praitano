// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Kismet/KismetMathLibrary.h"

AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	dectedBox = CreateDefaultSubobject<UBoxComponent>("Dected Trigger");
	dectedBox->SetupAttachment(RootComponent);
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	dectedBox->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnEnterDectedTrigger);
	dectedBox->OnComponentEndOverlap.AddDynamic(this, &AEnemy::OnExitDetectionTrigger);
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy::OnEnterDectedTrigger(UPrimitiveComponent* OvelappedComponnent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSwepp, const FHitResult& SweepResult)
{
	player = Cast<AFirstPerso>(OtherActor);
	if (!player)
		return;
	isDected = true;
	EnterDectedBehaviour(OtherActor);
}

void AEnemy::OnExitDetectionTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	player = Cast<AFirstPerso>(OtherActor);
	if (!player)
		return;
	isDected = true;
	ExitDectedBehaviour(OtherActor);
}

void AEnemy::EnterDectedBehaviour(AActor* _player)
{
}

void AEnemy::ExitDectedBehaviour(AActor* _player)
{
}

void AEnemy::LookAt(FVector _lookLocation)
{
	FRotator _lookat = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), _lookLocation);
	SetActorRotation(_lookat);
}

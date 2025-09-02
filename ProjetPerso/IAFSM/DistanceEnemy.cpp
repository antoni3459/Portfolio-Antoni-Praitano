// Fill out your copyright notice in the Description page of Project Settings.


#include "DistanceEnemy.h"

void ADistanceEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void ADistanceEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADistanceEnemy::Shoot()
{
	UE_LOG(LogTemp, Warning, TEXT("shoot"));
	AProjectile* _projectile = GetWorld()->SpawnActor<AProjectile>(projectil, GetActorLocation(), GetActorRotation());
}

void ADistanceEnemy::SpawnProjectile()
{

}

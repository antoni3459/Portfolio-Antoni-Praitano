// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(FMath::Lerp(GetActorLocation(), GetActorLocation() + GetActorForwardVector(), GetWorld()->DeltaTimeSeconds * speed));
}

void AProjectile::NotifyActorBeginOverlap(AActor* _other)
{
	Destroy();
}

void AProjectile::DestroyActor()
{
	Destroy();
}


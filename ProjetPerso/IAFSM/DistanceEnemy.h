// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "Projectile.h"
#include "DistanceEnemy.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API ADistanceEnemy : public AEnemy
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	int timeShoot = 3;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AProjectile> projectil;

	FTimerHandle timerShoot;


public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE int& GetTimeShoot() { return timeShoot; }

	void Shoot();

	void SpawnProjectile();
};

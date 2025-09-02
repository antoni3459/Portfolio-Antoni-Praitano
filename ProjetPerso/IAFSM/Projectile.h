// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class FIRSTPROJECTPERSO_API AProjectile : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	int speed = 500;

public:	
	AProjectile();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* _other)override;
	void DestroyActor();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "FirstPerso.h"
#include "Enemy.generated.h"

UCLASS()
class FIRSTPROJECTPERSO_API AEnemy : public APawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> dectedBox = nullptr;

	UPROPERTY(EditAnywhere)
	float speedRota = 100;

protected:
	UPROPERTY(EditAnywhere)
	int life = 10;
	UPROPERTY(EditAnywhere)
	int dammage = 20;
	UPROPERTY(EditAnywhere)
	int speed;

	UPROPERTY()
	bool isDected = false;

	UPROPERTY()
		TObjectPtr<AFirstPerso> player = nullptr;

public:
	AEnemy();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()void OnEnterDectedTrigger(UPrimitiveComponent* OvelappedComponnent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSwepp, const FHitResult& SweepResult);
	UFUNCTION() void OnExitDetectionTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void EnterDectedBehaviour(AActor* _player);
	virtual void ExitDectedBehaviour(AActor* _player);

public:
	void LookAt(FVector _lookLocation);
};

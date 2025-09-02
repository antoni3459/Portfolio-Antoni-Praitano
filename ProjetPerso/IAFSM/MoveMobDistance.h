// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DistanceEnemy.h"
#include "DetectPlayer.h"
#include "PointPosition.h"
#include "MoveMobDistance.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API AMoveMobDistance : public ADistanceEnemy
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TObjectPtr<UDetectPlayer> detect = nullptr;
	UPROPERTY(EditAnywhere)
	int nbrPass = 0;

	UPROPERTY()
	int currentPoint = 0;
	UPROPERTY()
	int reverse = 1;
	FVector pointMove;
	FVector newPosition;

public:
	AMoveMobDistance();
	FORCEINLINE UDetectPlayer* GetDetect()const { return detect; }

	FORCEINLINE FVector GetNewPosition()const { return newPosition; }
	FORCEINLINE void SetNewPosition(FVector _newPosition) { newPosition = FVector(_newPosition.X, _newPosition.Y, GetActorLocation().Z); }

	FORCEINLINE int GetNbrPass()const { return nbrPass; }
	FORCEINLINE void SetNbrPass(int _nbrPass) { nbrPass = _nbrPass; }

	FORCEINLINE float GetCurrentPoint()const { return currentPoint; }
	FORCEINLINE void SetCurrentPoint(int _currentPoint) { currentPoint = _currentPoint; }

protected:
	virtual void BeginPlay()override;
	virtual void Tick(float _deltaTime) override;
	void Debug();

public:
	void Move();
	FVector EndMove();
	void TimerShoot();
	void ClearTimerShoot();
};

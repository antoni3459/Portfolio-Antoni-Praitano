// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AstarAlgo.h"
#include "GridPointData.h"
#include "PointPosition.h"
#include "MoveMobDistance.h"
#include "IANavigationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIRSTPROJECTPERSO_API UIANavigationComponent : public UActorComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAstarAlgo> subAstar;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAstarAlgo> astar = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UGridPointData> data = nullptr;
	UPROPERTY()
	TObjectPtr<AMoveMobDistance> mob = nullptr;
	UPROPERTY()
	FVector endPoistion;

	int currentPoint = 0;

public:	
	UIANavigationComponent();
	FORCEINLINE FVector GetEndPosition()const { return data->GetCloseNode(endPoistion)->GetPosition(); }

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void Request(FVector _newPosition);
	void DrawDebug();
	void SetDestination();
	bool GetIsDestination();
};

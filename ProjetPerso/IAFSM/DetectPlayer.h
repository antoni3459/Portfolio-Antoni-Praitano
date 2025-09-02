// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DetectPlayer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIRSTPROJECTPERSO_API UDetectPlayer : public UActorComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TArray<TEnumAsByte< EObjectTypeQuery>> outLayer;
	UPROPERTY(EditAnywhere)
	TArray<TEnumAsByte< EObjectTypeQuery>> layerObstacles;
	UPROPERTY(EditAnywhere)
	float radius = 800;
	UPROPERTY(EditAnywhere)
	float sightAngle = 90;
	UPROPERTY()
	TObjectPtr<AActor> player = nullptr;
	UPROPERTY()
	FVector targetLocation;

public:	
	UDetectPlayer();
	FORCEINLINE AActor* GetPlayer()const { return player; }
	FORCEINLINE FVector GetTargetLocation()const { return targetLocation; }
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	bool Detect();
	float Angle(FVector _u, FVector _v);

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FirstPerso.h"
#include "FirstPersoAnim.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECTPERSO_API UFirstPersoAnim : public UAnimInstance
{
	GENERATED_BODY()
	UPROPERTY()
		TObjectPtr<AFirstPerso> firstPerso;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
		float speed = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
		float speedDirection = 0;

	virtual void NativeBeginPlay() override;

	UFUNCTION() void SetSpeed(float _speed);
	UFUNCTION() void SetSpeedDirection(float _speedDirection);




};

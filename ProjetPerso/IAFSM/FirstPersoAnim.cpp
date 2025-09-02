// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersoAnim.h"

void UFirstPersoAnim::NativeBeginPlay()
{
	firstPerso = Cast<AFirstPerso>(TryGetPawnOwner());
	if (!firstPerso)
		return;
	firstPerso->GetOnForward().AddDynamic(this, &UFirstPersoAnim::SetSpeed);
	firstPerso->GetOnDirection().AddDynamic(this, &UFirstPersoAnim::SetSpeedDirection);

}

void UFirstPersoAnim::SetSpeed(float _speed)
{
	speed = _speed;
}

void UFirstPersoAnim::SetSpeedDirection(float _speedDirection)
{
	speedDirection = _speedDirection;
}

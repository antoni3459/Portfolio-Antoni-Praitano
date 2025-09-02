// Fill out your copyright notice in the Description page of Project Settings.


#include "DetectPlayer.h"
#include "FirstPerso.h"
#include "Kismet/KismetSystemLibrary.h"

UDetectPlayer::UDetectPlayer()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UDetectPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void UDetectPlayer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Detect();
}

bool UDetectPlayer::Detect()
{
	FHitResult _result;

	const float _degrad = FMath::DegreesToRadians(sightAngle / 2);
	TArray<AActor*> _item;
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetOwner()->GetActorLocation(), radius, outLayer, nullptr, TArray<AActor*>(), _item);
	DrawDebugSphere(GetWorld(), GetOwner()->GetActorLocation(), radius, 100, player ? FColor::Green : FColor::Red);
	DrawDebugCone(GetWorld(), GetOwner()->GetActorLocation(), GetOwner()->GetActorForwardVector(), radius * 1.4f, _degrad, _degrad, 10, player ? FColor::Green : FColor::Red);
	for (int i = 0; i < _item.Num(); i++)
	{
		if (_item[i])
		{
			const FVector _direction = (_item[i]->GetActorLocation() - GetOwner()->GetActorLocation()).GetSafeNormal();
			float _angle = Angle(GetOwner()->GetActorForwardVector(), _direction);
			bool _ostacle = UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), GetOwner()->GetActorLocation(), _item[i]->GetActorLocation(), layerObstacles, false, TArray<AActor*>(), EDrawDebugTrace::ForOneFrame, _result, false);
			if (_ostacle)
				return false;
			if (_angle < sightAngle / 2)
			{
				player = _item[i];
				targetLocation = player->GetActorLocation();
				return true;
			}
		}
	}
	player = nullptr;
	return false;
}

float UDetectPlayer::Angle(FVector _u, FVector _v)
{
	const float _dot = FVector::DotProduct(_u, _v) / (_u.Size(), _v.Size());
	return FMath::RadiansToDegrees(FMath::Acos(_dot));
}


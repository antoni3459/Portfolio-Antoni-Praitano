// Fill out your copyright notice in the Description page of Project Settings.


#include "NodeNav.h"
#include "Kismet/KismetSystemLibrary.h"

void UNodeNav::CheckForObstacle()
{
	TArray<AActor*> _item;
	isClose = UKismetSystemLibrary::SphereOverlapActors(GetWorld(), position, 50, layers, nullptr, TArray<AActor*>(), _item);
}

void UNodeNav::DrawDebug()
{
	DrawDebugSphere(GetWorld(), position, 20, 10, isClose ? FColor::Black : FColor::Green);
	for (size_t i = 0; isSelected && i < successors.Num(); i++)
		DrawDebugLine(GetWorld(), position, grid->GetNodes()[successors[i]]->GetPosition(),FColor::Green);
}

void UNodeNav::ResetNode()
{
	h = TNumericLimits<float>::Max();
	g = TNumericLimits<float>::Max();;
	parent = nullptr;
}

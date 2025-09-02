// Fill out your copyright notice in the Description page of Project Settings.


#include "IANavigationComponent.h"

UIANavigationComponent::UIANavigationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UIANavigationComponent::BeginPlay()
{
	Super::BeginPlay();
	endPoistion = GetOwner()->GetActorLocation();
	mob = Cast<AMoveMobDistance>(GetOwner());
	astar = NewObject<UAstarAlgo>();
}

void UIANavigationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	DrawDebug();
	if (mob->GetNewPosition() == mob->GetActorLocation() && !astar->GetCorrectPath().IsEmpty())
	{
		currentPoint++;
		SetDestination();
	}
}

void UIANavigationComponent::Request(FVector _newPosition)
{
	currentPoint = 0;
	endPoistion = _newPosition;
	astar->ComputePath(data->GetCloseNode(GetOwner()->GetActorLocation()), data->GetCloseNode(_newPosition));
}

void UIANavigationComponent::DrawDebug()
{
	DrawDebugSphere(GetWorld(), GetEndPosition() + FVector::UpVector * 100, 20, 10, FColor::Magenta);
}

void UIANavigationComponent::SetDestination()
{
	if (mob->GetActorLocation() == GetEndPosition())
		return;
	mob->SetNewPosition(astar->GetCorrectPath()[currentPoint]->GetPosition());
	mob->LookAt(astar->GetCorrectPath()[currentPoint]->GetPosition());
}

bool UIANavigationComponent::GetIsDestination()
{
	return FVector().Dist(GetOwner()->GetActorLocation(), GetEndPosition())<50;
}

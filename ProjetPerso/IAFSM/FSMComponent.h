// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FSMObject.h"
#include "FSMComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIRSTPROJECTPERSO_API UFSMComponent : public UActorComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TSubclassOf<UFSMObject> fsm = nullptr;
	UPROPERTY()
	TObjectPtr<UFSMObject> currentFSM = nullptr;
public:	
	UFSMComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason)override;

public:
	virtual void StartFSM();
	virtual void TickFSM();
	virtual void CloseFSM();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridPointData.h"
#include "NodeNav.h"
#include "GridNav.generated.h"

UCLASS()
class FIRSTPROJECTPERSO_API AGridNav : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TSubclassOf<UNodeNav> subNode = nullptr;
	UPROPERTY(EditAnywhere)
	int size = 4;
	UPROPERTY(EditAnywhere)
	int gap = 1;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UGridPointData> data = nullptr;
	UPROPERTY(EditAnywhere)
	bool debugMode = true;

	UPROPERTY()
	bool isGenerate = false;

public:	
	AGridNav();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldTickIfViewportsOnly()const override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

public:
	UFUNCTION(CallInEditor,Category = "Spawn Grid") void Generate();
	UFUNCTION(CallInEditor, Category = "Spawn Grid") void Clear();
	void SetSuccessor();
	void Debug();
};

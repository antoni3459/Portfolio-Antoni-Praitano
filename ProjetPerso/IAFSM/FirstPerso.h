// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputMappingContext.h"
#include "FirstPerso.generated.h"

UCLASS()
class FIRSTPROJECTPERSO_API AFirstPerso : public ACharacter
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnForward, float, _axis);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDirection, float, _axis);

	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;

	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> arm = nullptr;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UInputMappingContext> context = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> forwardInput = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> rightInput = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> mouseX = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> mouseY = nullptr;


	UPROPERTY(EditAnywhere)
		float cameraClampPitch = 90;
	UPROPERTY(EditAnywhere)
		float speed = 100;

	FOnForward onForward;
	FOnDirection onDirection;


public:
	AFirstPerso();

	FORCEINLINE FOnForward& GetOnForward() { return onForward; }
	FORCEINLINE FOnDirection& GetOnDirection() { return onDirection; }

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(const FInputActionValue& _value);
	void Direction(const FInputActionValue& _value);
	void RotationCameraYaw(const FInputActionValue& _value);
	void RotationCameraPitch(const FInputActionValue& _value);
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPerso.h"
#include "InputUtils.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

#include <Kismet/KismetMathLibrary.h>

AFirstPerso::AFirstPerso()
{
	PrimaryActorTick.bCanEverTick = true;
	
	arm = CreateDefaultSubobject<USpringArmComponent>("arm");
	camera = CreateDefaultSubobject<UCameraComponent>("camera");
	arm->SetupAttachment(RootComponent);
	camera->SetupAttachment(arm);
}

void AFirstPerso::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* _player = GetWorld()->GetFirstPlayerController();
	UEnhancedInputLocalPlayerSubsystem* _system = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem>(_player->GetLocalPlayer());
	_system->ClearAllMappings();
	_system->AddMappingContext(context.LoadSynchronous(), 0);
}

void AFirstPerso::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFirstPerso::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* _input = Cast< UEnhancedInputComponent>(PlayerInputComponent);
	_input->BindAction(forwardInput,ETriggerEvent::Triggered, this, &AFirstPerso::MoveForward);
	_input->BindAction(forwardInput,ETriggerEvent::Completed, this, &AFirstPerso::MoveForward);
	_input->BindAction(rightInput, ETriggerEvent::Triggered, this, &AFirstPerso::Direction);
	_input->BindAction(rightInput, ETriggerEvent::Completed, this, &AFirstPerso::Direction);
	_input->BindAction(mouseX, ETriggerEvent::Triggered, this, &AFirstPerso::RotationCameraYaw);
	_input->BindAction(mouseY, ETriggerEvent::Triggered, this, &AFirstPerso::RotationCameraPitch);
}

void AFirstPerso::MoveForward(const FInputActionValue& _value)
{
	float _axis = _value.Get<float>();
	if (_axis < -0.5)
		GetMesh()->SetRelativeRotation(FRotator(0, arm->GetRelativeRotation().Yaw - 180, 0));
	else if (_axis > 0.5)
		GetMesh()->SetRelativeRotation(FRotator(0, arm->GetRelativeRotation().Yaw, 0));
	AddMovementInput((GetMesh()->GetForwardVector()) * FMath::Abs(_axis) * speed);

	onForward.Broadcast(_axis);
}

void AFirstPerso::Direction(const FInputActionValue& _value)
{
	float _axis = _value.Get<float>();
	if (_axis < -0.5)
		GetMesh()->SetRelativeRotation(FRotator(0, arm->GetRelativeRotation().Yaw, 0));
	else if (_axis > 0.5)
		GetMesh()->SetRelativeRotation(FRotator(0, arm->GetRelativeRotation().Yaw, 0));
	AddMovementInput((GetMesh()->GetRightVector()) * _axis);
	onDirection.Broadcast(_axis);
}

void AFirstPerso::RotationCameraYaw(const FInputActionValue& _value)
{
	float _axis = _value.Get<float>();
	arm->AddWorldRotation(FRotator(0, 1, 0) * _axis);
}

void AFirstPerso::RotationCameraPitch(const FInputActionValue& _value)
{
	float _axis = _value.Get<float>();
	float _pitch = arm->GetRelativeRotation().Pitch;
	float _newPitch = _pitch + _axis;

	if (_newPitch <= -cameraClampPitch)
	{
		arm->SetRelativeRotation(FRotator(-cameraClampPitch, arm->GetRelativeRotation().Yaw, arm->GetRelativeRotation().Roll));
		return;
	}
	if (_newPitch >= cameraClampPitch)
	{
		arm->SetRelativeRotation(FRotator(cameraClampPitch, arm->GetRelativeRotation().Yaw, arm->GetRelativeRotation().Roll));
		return;
	}
	arm->AddLocalRotation(FRotator(1, 0, 0) * _axis);
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChar.h"
#include "PlayerMovementComponent.h"
#include <Engine/Classes/Components/CapsuleComponent.h>
#include <Engine/Classes/Camera/CameraComponent.h>

APlayerChar::APlayerChar()
{
	PrimaryActorTick.bCanEverTick = true;

	Movement = CreateDefaultSubobject<UPlayerMovementComponent>(TEXT("Player Movement Component"));
	Movement->UpdatedComponent = RootComponent;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera->SetupAttachment(RootComponent);
	Camera->SetRelativeLocation(FVector(25.0f, 0.0f, 65.0f));
}

void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Log, TEXT("[LOAD] Player Character"));
}

void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// if stopped run and not ready to run or not taking break, make avaliable to run after some time
	if (!bReadySprint && Movement->move_speed != 400 && !bTakingBreak) {
		bTakingBreak = true;

		FTimerHandle instantTimerHandle;
		const float breakTime = 5.0f;
		GetWorldTimerManager()
			.SetTimer(instantTimerHandle, this, &APlayerChar::ReadySprint, breakTime, false);
	}
}

void APlayerChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UE_LOG(LogTemp, Log, TEXT("[fun] setup input component"));
	InputComponent->BindAxis("MoveForward", this, &APlayerChar::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerChar::MoveRight);
	InputComponent->BindAxis("Turn", this, &APlayerChar::Turn);
	InputComponent->BindAxis("Lookup", this, &APlayerChar::Lookup);

	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerChar::BJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APlayerChar::EJump);

	InputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerChar::BSprint);
	InputComponent->BindAction("Sprint", IE_Released, this, &APlayerChar::ESprint);
}

void APlayerChar::MoveForward(float AxisValue)
{
	bMoveBack = false;
	bMoveNACHVORNE = false;
	if (Movement && !bMoveRight && !bMoveLeft) {
		if (AxisValue > 0) {
			bMoveNACHVORNE = true;
			Movement->AddMoveVelocity(GetActorForwardVector() * AxisValue);
		}
		else if(AxisValue < 0) {
			bMoveBack = true;
			Movement->AddMoveVelocity(GetActorForwardVector() * AxisValue / 2);
		}
	}
}

void APlayerChar::MoveRight(float AxisValue)
{
	bMoveRight = false;
	bMoveLeft = false;
	if (Movement && !bMoveNACHVORNE && !bMoveBack) {
		if (Movement->move_speed != 400) {
			if (AxisValue > 0) {
				bMoveRight = true;
			}
			else if (AxisValue < 0) {
				bMoveLeft = true;
			}
			Movement->AddMoveVelocity(GetActorRightVector() * AxisValue / 4);
		}
	}
}

void APlayerChar::Turn(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void APlayerChar::Lookup(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
	Camera->SetWorldRotation(GetControlRotation());
}

void APlayerChar::BJump()
{
	bWalking = false;
	Movement->jump_request = true;
}

void APlayerChar::EJump()
{
	Movement->jump_request = false;
}

void APlayerChar::BSprint()
{
	if (bReadySprint) {
		bReadySprint = false;
		Movement->move_speed = 400;
		if (!Movement->recent_move_velocity.IsNearlyZero()) Camera->SetRelativeLocation(FVector(40.0f, 0.0f, 55.0f));
	}
}

void APlayerChar::ESprint()
{
	Movement->move_speed = 250;
	FTimerHandle instantTimerHandle;
	GetWorldTimerManager()
		.SetTimer(instantTimerHandle, this, &APlayerChar::ResetCamera, 0.1f, false);
}

void APlayerChar::ResetCamera()
{
	Camera->SetRelativeLocation(FVector(25.0f, 0.0f, 65.0f));
}

void APlayerChar::ReadySprint()
{
	bReadySprint = true;
	bTakingBreak = false;
}
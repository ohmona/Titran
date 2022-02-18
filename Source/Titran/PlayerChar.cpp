// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChar.h"
#include "PlayerMovementComponent.h"

APlayerChar::APlayerChar()
{
	PrimaryActorTick.bCanEverTick = true;

	Movement = CreateDefaultSubobject<UPlayerMovementComponent>(TEXT("Player Movement Component"));
	Movement->UpdatedComponent = RootComponent;
}

void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Log, TEXT("[LOAD] Player Character"))
}

void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
}

void APlayerChar::MoveForward(float AxisValue)
{
	if (Movement) {
		Movement->AddMoveVelocity(GetActorForwardVector() * AxisValue);
	}
}

void APlayerChar::MoveRight(float AxisValue)
{
	if (Movement) {
		Movement->AddMoveVelocity(GetActorRightVector() * AxisValue);
	}
}

void APlayerChar::Turn(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void APlayerChar::Lookup(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void APlayerChar::BJump()
{
	Movement->jump_request = true;
}

void APlayerChar::EJump()
{
	Movement->jump_request = false;
}
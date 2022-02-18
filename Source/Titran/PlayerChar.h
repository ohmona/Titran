// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerChar.generated.h"

UCLASS()
class TITRAN_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerChar();

	class UPlayerMovementComponent* Movement;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float AxisValue);
	void Lookup(float AxisValue);

	void BJump();
	void EJump();
};

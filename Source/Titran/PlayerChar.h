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

	UPROPERTY(BlueprintReadOnly) bool bWalking = false;
	UPROPERTY(BlueprintReadOnly) bool bSprinting = false;
	UPROPERTY(BlueprintReadOnly) bool bJumping = false;

	UPROPERTY(BlueprintReadOnly) bool bMoveLeft = false;
	UPROPERTY(BlueprintReadOnly) bool bMoveRight = false;
	UPROPERTY(BlueprintReadOnly) bool bMoveBack = false;
	UPROPERTY(BlueprintReadOnly) bool bMoveNACHVORNE = false;

	bool bReadySprint = true;
	bool bTakingBreak = false;

public:
	class UPlayerMovementComponent* Movement;
	UPROPERTY(EditAnywhere) class UCameraComponent* Camera;

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

	void BSprint();
	void ESprint();

	void ResetCamera();
	void ReadySprint();
};

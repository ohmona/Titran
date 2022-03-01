// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ThirdPersonComponent.h"
#include "PlayerChar.generated.h"

UCLASS()
class TITRAN_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerChar();

	UPROPERTY(BlueprintReadOnly, replicated) bool bWalking = false;
	UPROPERTY(BlueprintReadOnly, replicated) bool bSprinting = false;
	UPROPERTY(BlueprintReadOnly) bool bJumping = false;

	UPROPERTY(BlueprintReadOnly) bool bMoveLeft = false;
	UPROPERTY(BlueprintReadOnly) bool bMoveRight = false;
	UPROPERTY(BlueprintReadOnly) bool bMoveBack = false;
	UPROPERTY(BlueprintReadOnly) bool bMoveNACHVORNE = false;

	bool bReadySprint = true;
	bool bTakingBreak = false;

	bool bFirstPerson = true;

public:
	class UPlayerMovementComponent* Movement;
	UPROPERTY(EditAnywhere, BlueprintReadOnly) class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadOnly) class UThirdPersonComponent* ThirdPerson;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const;

/* Movement function */
public:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float AxisValue);
	void Lookup(float AxisValue);

	void BJump();
	void EJump();

	void BSprint();
	void ESprint();

	void BSelect();
	void ESelect();

	void ResetCamera();
	void ReadySprint();

/* Movement replication */
public:
	UFUNCTION(Server, Unreliable) void SMF(float AxisValue);
	UFUNCTION(Server, Unreliable) void SMR(float AxisValue);

	UFUNCTION(NetMulticast, Unreliable) void MMF(float AxisValue);
	UFUNCTION(NetMulticast, Unreliable) void MMR(float AxisValue);

	UFUNCTION(Server, Unreliable) void SBJ();
	UFUNCTION(Server, Unreliable) void SEJ();

	UFUNCTION(NetMulticast, Unreliable) void MBJ();
	UFUNCTION(NetMulticast, Unreliable) void MEJ();

	UFUNCTION(Server, Unreliable) void SBS();
	UFUNCTION(Server, Unreliable) void SES();

	UFUNCTION(NetMulticast, Unreliable) void MBS();
	UFUNCTION(NetMulticast, Unreliable) void MES();
public:

	void ChangeView();

	FHitResult DoLineTrace();
};

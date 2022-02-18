// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class TITRAN_API UPlayerMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	UPlayerMovementComponent();

	// default
	float gravity = 9.8f;

	// move
	FVector move_velocity = FVector::ZeroVector;
	FVector recent_move_velocity = FVector::ZeroVector;
	float move_speed = 250;

	// jump
	FVector origin_Z = FVector::ZeroVector;
	bool jump_request = false;
	bool jump_ready = true;
	bool is_jumping = false;
	float time_jump = 0.0f;
	float jump_force = 15.0f;
	float jump_speed = 5.0f;

	// floor
	bool b_on_floor = false;
	float floor_distance = 0.0f;
	FFindFloorResult Floor;

public:
	virtual void TickComponent(
		float DeltaTime, 
		enum ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;

	void AddMoveVelocity(FVector velocity);
	void ClearMoveVelocity();
};

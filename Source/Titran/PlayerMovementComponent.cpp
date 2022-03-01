// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovementComponent.h"
#include <Titran/PlayerChar.h>
#include <Engine/Classes/Camera/CameraComponent.h>
#include <Net/UnrealNetwork.h>

UPlayerMovementComponent::UPlayerMovementComponent() {
}

void UPlayerMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)) {
        return;
    }

    // original location of actor
    FVector origin = PawnOwner.Get()->GetActorLocation();

    // some floor codes
    FindFloor(GetActorLocation(), Floor, true);
    b_on_floor = Floor.bBlockingHit;
    floor_distance = Floor.GetDistanceToFloor();

    if (!b_on_floor) AddMoveVelocity(FVector(0.0f, 0.0f, -0.98));


    Cast<APlayerChar>(PawnOwner)->bJumping = false;
    // start jump if requested and ready
    if (jump_request && jump_ready) {
        jump_ready = false;
        is_jumping = true;

        Cast<APlayerChar>(PawnOwner)->Camera->SetRelativeLocation(FVector(25.0f, 0.0f, 58.0f));
    }

    // Add frame vector after formel https://tenlie10.tistory.com/124
    // (-gravity / 2) * time^2 + (time * jump_force)
    FVector jumpVector = FVector::ZeroVector;
    if (is_jumping) {
        jumpVector.Z = (FMath::Square(time_jump) * ((-gravity) / 2)) + (time_jump * jump_force);
        if (!jumpVector.IsZero()) {
            Cast<APlayerChar>(PawnOwner)->SetActorLocation(jumpVector + origin, false, nullptr, ETeleportType::TeleportPhysics);
        }
        time_jump += DeltaTime * jump_speed;
        ClearMoveVelocity();

        Cast<APlayerChar>(PawnOwner)->bJumping = true;
    }

    // if it's jumping, z-vector is negative and time is running, disable jump
    if (is_jumping && jumpVector.Z < 0 && time_jump > 0) {
        time_jump = 0;
        jump_ready = true;
        is_jumping = false;

        FTimerHandle instantTimerHandle;
        Cast<APlayerChar>(PawnOwner)->GetWorldTimerManager()
            .SetTimer(instantTimerHandle, Cast<APlayerChar>(PawnOwner), &APlayerChar::ResetCamera, 0.075f, false);
        Cast<APlayerChar>(PawnOwner)->bJumping = false;
    }

    // Apply move vector
    if (!move_velocity.IsZero() && !is_jumping) {
        FVector desiration = origin + (move_velocity * move_speed * DeltaTime);
        FHitResult* hit = nullptr;

        Cast<APlayerChar>(PawnOwner)->SetActorLocation(desiration, true, hit, ETeleportType::TeleportPhysics);
    }
    recent_move_velocity = move_velocity;
    move_velocity = FVector::ZeroVector;
};

void UPlayerMovementComponent::AddMoveVelocity(FVector velocity)
{
    move_velocity += velocity;
}

void UPlayerMovementComponent::ClearMoveVelocity()
{
    move_velocity = FVector::ZeroVector;
}
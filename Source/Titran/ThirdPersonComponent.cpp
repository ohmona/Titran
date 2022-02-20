// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonComponent.h"
#include <GameFramework/SpringArmComponent.h>
#include <Engine/Classes/Camera/CameraComponent.h>

UThirdPersonComponent::UThirdPersonComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(this);
	SpringArm->SetRelativeLocation(ActorDistance);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 0.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->Deactivate();
}


void UThirdPersonComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UThirdPersonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


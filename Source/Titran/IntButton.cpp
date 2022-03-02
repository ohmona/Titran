// Fill out your copyright notice in the Description page of Project Settings.


#include "IntButton.h"
#include <Engine/Classes/Components/SkeletalMeshComponent.h>
#include <Net/UnrealNetwork.h>

// Sets default values
AIntButton::AIntButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	root = RootComponent;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	Mesh->SetCollisionProfileName(TEXT("BlockAll"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AIntButton::BeginPlay()
{
	Super::BeginPlay();
	
}

void AIntButton::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AIntButton, bClicked);
}

// Called every frame
void AIntButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIntButton::Click()
{
	bClicked = true;
	FTimerHandle instantTimerHandle;
	GetWorldTimerManager().SetTimer(instantTimerHandle, this, &AIntButton::Reset, 2.0f, false);
}

void AIntButton::Reset()
{
	bClicked = false;
}

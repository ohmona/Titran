// Copyright Epic Games, Inc. All Rights Reserved.


#include "TitranGameModeBase.h"
#include <Titran/TitranSession.h>
#include "LobbyGameState.h"

ATitranGameModeBase::ATitranGameModeBase()
{
	GameSessionClass = ATitranSession::StaticClass();
}

void ATitranGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* controller = GetWorld()->GetFirstPlayerController();

	controller->bShowMouseCursor = false;
	controller->SetInputMode(FInputModeGameOnly());
}

void ATitranGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATitranGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}
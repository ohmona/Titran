// Copyright Epic Games, Inc. All Rights Reserved.


#include "TitranGameModeBase.h"
#include <Titran/TitranSession.h>

ATitranGameModeBase::ATitranGameModeBase()
{
	GameSessionClass = ATitranSession::StaticClass();
}

void ATitranGameModeBase::BeginPlay()
{
	APlayerController* controller = GetWorld()->GetFirstPlayerController();

	controller->bShowMouseCursor = false;
	controller->SetInputMode(FInputModeGameOnly());
}

void ATitranGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

}
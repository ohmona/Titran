// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameState.h"

void ALobbyGameState::MovePlayer()
{
	GetWorld()->GetAuthGameMode()->ProcessServerTravel(TEXT("Default"), true);
}
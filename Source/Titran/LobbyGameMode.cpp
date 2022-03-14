// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "LobbyGameState.h"
#include "TitranPlayerController.h"

void ALobbyGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ALobbyGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ALobbyGameState* lobbystate = GetGameState<ALobbyGameState>();
	if (lobbystate != nullptr) {
		/* if readied player is over half of player, start game */
		// ex 4 players and 3 readied players cuy its over 2 players
		if (lobbystate->player_count / 2 < lobbystate->readied_player) {
			lobbystate->BPLoadEveryPlayer();
			/* Lobby ends here */
		}
	}
}

void ALobbyGameMode::WarpAll()
{
}

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	NewPlayer->GetPlayerState<ATitranPlayerState>()->ready_state = EReadyState::WAITING;

	ALobbyGameState* lobbystate = GetGameState<ALobbyGameState>();
	if (lobbystate != nullptr) {
		lobbystate->player_count++;
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}
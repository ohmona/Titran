// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TitranGameStateBase.h"
#include "LobbyGameState.generated.h"

/**
 * 
 */
UCLASS()
class TITRAN_API ALobbyGameState : public ATitranGameStateBase
{
	GENERATED_BODY()
	
public:
	int32 player_count = 0;
	int32 readied_player = 0;

public:
	UFUNCTION(BlueprintCallable) void MovePlayer();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable) void BPLoadEveryPlayer();
};

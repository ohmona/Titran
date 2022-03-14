// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TitranGameModeBase.h"
#include "TitranPlayerState.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TITRAN_API ALobbyGameMode : public ATitranGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void Logout(AController* Exiting) override;

	void WarpAll();
};

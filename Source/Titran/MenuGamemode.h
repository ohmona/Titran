// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TitranGameModeBase.h"
#include <Titran/TitranSession.h>
#include <Titran/TitranInstance.h>
#include "MenuGamemode.generated.h"

/**
 * 
 */
UCLASS()
class TITRAN_API AMenuGamemode : public ATitranGameModeBase
{
	GENERATED_BODY()
	
public:
	AMenuGamemode();

	UPROPERTY(BlueprintReadWrite) bool bSucces = false;
	UPROPERTY(BlueprintReadWrite) bool bUseLan = true;
	UPROPERTY(BlueprintReadWrite) FName IpAdress = FName("127.0.0.1");

	ATitranSession* SessionInstance;

protected:
	virtual void BeginPlay() override;

public:
	void GameHost();
	void GameJoin();

protected:
	UFUNCTION(BlueprintImplementableEvent) void BP_GH(APlayerController* controller, int32 max_player_count, bool bUse_lan);
	UFUNCTION(BlueprintImplementableEvent) void BP_GJ(APlayerController* controller, int32 max_serach_result, bool bUse_lan);
};

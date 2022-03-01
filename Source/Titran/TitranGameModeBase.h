// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TitranGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TITRAN_API ATitranGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ATitranGameModeBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
};

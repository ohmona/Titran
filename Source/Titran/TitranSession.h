// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "TitranSession.generated.h"

/**
 * 
 */
UCLASS()
class TITRAN_API ATitranSession : public AGameSession
{
	GENERATED_BODY()
	
public:
	ATitranSession();

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
};

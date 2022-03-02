// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TitranPlayerState.generated.h"

UENUM(BlueprintType)
enum class EReadyState : uint8 {
	WAITING UMETA(DisplayName = "waiting"),
	READY UMETA(DisplayName = "ready"),
	NONE UMETA(DisplayName = "none")
};

/**
 * 
 */
UCLASS()
class TITRAN_API ATitranPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	EReadyState ready_state = EReadyState::NONE;
};

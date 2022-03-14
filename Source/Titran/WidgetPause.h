// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetPause.generated.h"

/**
 * 
 */
UCLASS()
class TITRAN_API UWidgetPause : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void Continue();

	UFUNCTION(BlueprintCallable)
	void LeaveSession();

	UFUNCTION(BlueprintCallable)
	void Setting();
};

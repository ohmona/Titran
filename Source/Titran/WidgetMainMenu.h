// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class TITRAN_API UWidgetMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite) int32 z;

	UPROPERTY(BlueprintReadWrite) TSubclassOf<UUserWidget> aftWidget;

public:
	UFUNCTION(BlueprintCallable) void Exit();
	UFUNCTION(BlueprintCallable) void Host();
	UFUNCTION(BlueprintCallable) void Join();
	UFUNCTION(BlueprintCallable) void ReturnWidget();
	UFUNCTION(BlueprintCallable) void ContinueWidget();
};

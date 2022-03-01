// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGamemode.h"
#include <Blueprint/UserWidget.h>
#include <Titran/TitranSession.h>

AMenuGamemode::AMenuGamemode()
{
	GameSessionClass = ATitranSession::StaticClass();
}

void AMenuGamemode::BeginPlay()
{
	APlayerController* controller = GetWorld()->GetFirstPlayerController();

	controller->bShowMouseCursor = true;
	controller->SetInputMode(FInputModeUIOnly());
}

/* Create a Session and ready for join other people */
void AMenuGamemode::GameHost()
{
	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	const int32 max_player = 20;

	BP_GH(controller, max_player, bUseLan);

	if (bSucces) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Host Succesful");
		bSucces = false;
	}
}

/* Search available sessions and try to join */
void AMenuGamemode::GameJoin()
{
	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	const int32 max_result = 20;

	BP_GJ(controller, max_result, bUseLan);

	if (bSucces) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Join Succesful");
		bSucces = false;
	}
}

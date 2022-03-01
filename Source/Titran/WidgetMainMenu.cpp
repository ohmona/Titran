// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetMainMenu.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Titran/MenuGamemode.h>


void UWidgetMainMenu::Exit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), GetOwningPlayer(), EQuitPreference::Quit, true);
}

void UWidgetMainMenu::Host()
{
	AMenuGamemode* game = Cast<AMenuGamemode>(GetWorld()->GetAuthGameMode());
	game->GameHost();
}

void UWidgetMainMenu::Join()
{
	AMenuGamemode* game = Cast<AMenuGamemode>(GetWorld()->GetAuthGameMode());
	game->GameJoin();
}

/* remove current widget */
void UWidgetMainMenu::ReturnWidget()
{
	if (z > 0) {
		this->RemoveFromParent();
	}
}

/* Create child widget on current widget */
void UWidgetMainMenu::ContinueWidget()
{
	APlayerController* controller = GetOwningPlayer();
	UUserWidget* widget = CreateWidget(controller, aftWidget);
	widget->AddToViewport(z + 1);
}
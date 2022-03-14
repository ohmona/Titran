// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetPause.h"
#include "TitranPlayerController.h"

void UWidgetPause::Continue()
{
	RemoveFromParent();
}

void UWidgetPause::LeaveSession()
{
	ATitranPlayerController* controller = GetOwningPlayer<ATitranPlayerController>();
	controller->ClientTravel("Main", ETravelType::TRAVEL_Partial, false);
	controller->ClientTravel("127.0.01", ETravelType::TRAVEL_Absolute, false);
	controller->ClientEndOnlineSession();
	/* User is no more on server */
}

void UWidgetPause::Setting()
{

}
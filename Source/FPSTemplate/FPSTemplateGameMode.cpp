// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSTemplateGameMode.h"
#include "FPSTemplateHUD.h"
#include "FPSTemplateCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSTemplateGameMode::AFPSTemplateGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSTemplateHUD::StaticClass();
}

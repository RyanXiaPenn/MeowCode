// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MeowCodeGameMode.h"
#include "MeowCodeHUD.h"
#include "MeowCodeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMeowCodeGameMode::AMeowCodeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMeowCodeHUD::StaticClass();
}

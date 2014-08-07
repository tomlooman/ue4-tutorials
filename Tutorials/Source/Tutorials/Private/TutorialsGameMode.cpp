// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "Tutorials.h"
#include "TutorialsGameMode.h"
#include "TutorialsHUD.h"

ATutorialsGameMode::ATutorialsGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/UsableActorCpp/BP_UsableCppCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATutorialsHUD::StaticClass();
}

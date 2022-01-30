// Copyright Epic Games, Inc. All Rights Reserved.

#include "Mythiary_TestGameMode.h"
#include "Mythiary_TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMythiary_TestGameMode::AMythiary_TestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

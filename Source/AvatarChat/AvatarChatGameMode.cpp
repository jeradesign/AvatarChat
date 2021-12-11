// Copyright Epic Games, Inc. All Rights Reserved.

#include "AvatarChatGameMode.h"
#include "AvatarChatCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAvatarChatGameMode::AAvatarChatGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

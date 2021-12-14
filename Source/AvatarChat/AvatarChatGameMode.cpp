// Copyright Epic Games, Inc. All Rights Reserved.

#include "AvatarChatGameMode.h"
#include "AvatarChatCharacter.h"
#include "MyCheckNull.h"
#include "GameFramework/GameState.h"
#include "UObject/ConstructorHelpers.h"
#include "ACGameState.h"

AAvatarChatGameMode::AAvatarChatGameMode()
{
	UE_LOG(LogTemp, Warning, TEXT("AAvatarChatGameMode::AAvatarChatGameMode"));
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	MYCHECKNULL(PlayerPawnBPClass.Class);
	DefaultPawnClass = PlayerPawnBPClass.Class;

	GameStateClass = AACGameState::StaticClass();
}

void AAvatarChatGameMode::InitGameState()
{
	Super::InitGameState();
	UE_LOG(LogTemp, Warning, TEXT("AAvatarChatGameMode::InitGameState"));
}

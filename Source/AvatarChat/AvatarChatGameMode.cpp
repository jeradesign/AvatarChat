// Copyright Epic Games, Inc. All Rights Reserved.

#include "AvatarChatGameMode.h"
#include "AvatarChatCharacter.h"
#include "MyCheckNull.h"
#include "GameFramework/GameState.h"
#include "UObject/ConstructorHelpers.h"
#include "ACGameState.h"
#include "ACPlayerController.h"
#include "GameFramework/PlayerState.h"

AAvatarChatGameMode::AAvatarChatGameMode()
{
	UE_LOG(LogTemp, Warning, TEXT("AAvatarChatGameMode::AAvatarChatGameMode"));
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	MYCHECKNULL(PlayerPawnBPClass.Class);
	DefaultPawnClass = PlayerPawnBPClass.Class;

	GameStateClass = AACGameState::StaticClass();
	PlayerControllerClass = AACPlayerController::StaticClass();
}

void AAvatarChatGameMode::InitGameState()
{
	Super::InitGameState();
	UE_LOG(LogTemp, Warning, TEXT("AAvatarChatGameMode::InitGameState"));
}

void AAvatarChatGameMode::ChangeName(AController* Controller, const FString& NewName, bool bNameChange)
{
	UE_LOG(LogTemp, Warning, TEXT("AAvatarChatGameMode::ChangeName: %s, bNameChange = %d"),
		*NewName, bNameChange);
	Super::ChangeName(Controller, NewName, bNameChange);
	APlayerState* PlayerState(Controller->GetPlayerState<APlayerState>());
	UE_LOG(LogTemp, Warning, TEXT("After Super::ChangeName, Name = %s"), *PlayerState->GetName());
}

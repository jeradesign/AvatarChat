// Copyright 2021 Jera Design LLC. Use permitted under terms of LICENSE.txt


#include "ACPlayerController.h"

#include "ACGameState.h"
#include "MyCheckNull.h"

void AACPlayerController::SendMessage_Implementation(const FString& Message)
{
	UE_LOG(LogTemp, Warning, TEXT("AACPlayerController::SendMessage_Implementation: %s"), *Message);
	UWorld* World(GetWorld());
	MYCHECKNULL(World);
	AACGameState* GameState(World->GetGameState<AACGameState>());
	GameState->AddMessage(Message);
}

bool AACPlayerController::SendMessage_Validate(const FString& Message)
{
	return true;	// ironic writing this the week of Log4Shell
}


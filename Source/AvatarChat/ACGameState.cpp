// Copyright 2021 Jera Design LLC. Use permitted under terms of LICENSE.txt


#include "ACGameState.h"

#include "ACGameInstance.h"
#include "MyCheckNull.h"
#include "Net/UnrealNetwork.h"

AACGameState::AACGameState()
{
	UE_LOG(LogTemp, Warning, TEXT("AACGameState::AACGameState"));
}

void AACGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	UE_LOG(LogTemp, Warning, TEXT("AACGameState::GetLifetimeReplicatedProps"));
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AACGameState, Transcript);
}

void AACGameState::AddMessage_Implementation(const FString& Message)
{
	UE_LOG(LogTemp, Warning, TEXT("AACGameState::AddMessage: %s"), *Message);
	if (Transcript.IsEmpty())
	{
		Transcript = Message;
	}
	else
	{
		Transcript.Append(Message);
	}
}

bool AACGameState::AddMessage_Validate(const FString& Message)
{
	return true;
}

void AACGameState::UpdateTranscript(FString MyTranscript)
{
	UE_LOG(LogTemp, Warning, TEXT("AACGameState::UpdateTranscript: %s"), *MyTranscript);
	UACGameInstance* GameInstance(static_cast<UACGameInstance*>(GetGameInstance()));
	MYCHECKNULL(GameInstance);
	GameInstance->UpdateTranscript(MyTranscript);
}

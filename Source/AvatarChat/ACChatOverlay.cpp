// Copyright 2021 Jera Design LLC. Use permitted under terms of LICENSE.txt


#include "ACChatOverlay.h"

#include "MyCheckNull.h"
#include "Components/MultiLineEditableTextBox.h"


void UACChatOverlay::LogMessage(const FString& Message) const
{
	MYCHECKNULL(Transcript);
	const FText Text = Transcript->GetText();
	const FString OldString = Text.ToString();
	const FString NewString = OldString + FString("\n") + Message;
	UpdateTranscript(NewString);
}

void UACChatOverlay::UpdateTranscript(const FString& NewTranscriptString) const
{
	UE_LOG(LogTemp, Warning, TEXT("UACChatOverlay::UpdateTranscript: %s"), *NewTranscriptString);
	const FText NewText(FText::FromString(NewTranscriptString));
	MYCHECKNULL(Transcript);
	Transcript->SetText(NewText);
}

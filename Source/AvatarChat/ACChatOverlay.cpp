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
	const FText NewText(FText::FromString(NewString));
	Transcript->SetText(NewText);
}

// Copyright 2021 Jera Design LLC. Use permitted under terms of LICENSE.txt

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "ACChatOverlay.generated.h"

/**
 *
 */
UCLASS()
class AVATARCHAT_API UACChatOverlay : public UUserWidget
{
	GENERATED_BODY()

public:
	void LogMessage(const FString& Message) const;

private:
	UPROPERTY(meta = (BindWidget))
	class UMultiLineEditableTextBox *Transcript;
};

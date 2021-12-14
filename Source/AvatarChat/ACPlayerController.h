// Copyright 2021 Jera Design LLC. Use permitted under terms of LICENSE.txt

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ACPlayerController.generated.h"

/**
 *
 */
UCLASS()
class AVATARCHAT_API AACPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable, WithValidation)
	void SendMessage(const FString& Message);
};

// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameFramework/GameModeBase.h"
#include "AvatarChatGameMode.generated.h"

UCLASS(minimalapi)
class AAvatarChatGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAvatarChatGameMode();

	virtual void InitGameState() override;

	virtual void ChangeName(AController* Controller, const FString& NewName, bool bNameChange) override;
};




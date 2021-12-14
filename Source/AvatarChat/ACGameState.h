// Copyright 2021 Jera Design LLC. Use permitted under terms of LICENSE.txt

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Net/UnrealNetwork.h"
#include "ACGameState.generated.h"

/**
 *
 */
UCLASS()
class AVATARCHAT_API AACGameState : public AGameStateBase
{
	GENERATED_BODY()

	AACGameState();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(ReplicatedUsing=UpdateTranscript)
	FString Transcript;

	UFUNCTION()
	void UpdateTranscript(FString MyTranscript);

public:
	UFUNCTION(Server, Reliable, WithValidation)
	void AddMessage(const FString& Message);
};

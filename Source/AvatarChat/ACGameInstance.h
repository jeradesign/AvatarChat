// Copyright 2021 Jera Design LLC. Use permitted under terms of LICENSE.txt

#pragma once

#include "CoreMinimal.h"
#include "ACChatOverlay.h"
#include "Engine/GameInstance.h"
#include "ACGameInstance.generated.h"

/**
 *
 */
UCLASS()
class AVATARCHAT_API UACGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	explicit UACGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

	UFUNCTION(Exec, BlueprintCallable, Category="Chat System")
	void LoadChatOverlay();

	UFUNCTION(Exec, BlueprintCallable, Category="Chat System")
	void SendMessage(const FString& Message);

	UFUNCTION(Exec)
	virtual void BeginHosting();

	UFUNCTION(Exec)
	virtual void JoinServer(const FString& IpAddr);

private:
	TSubclassOf<UUserWidget> ChatOverlayClass;

	UPROPERTY()
	UACChatOverlay* ChatOverlay;
};

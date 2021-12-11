// Copyright 2021 Jera Design LLC. Use permitted under terms of LICENSE.txt


#include "ACGameInstance.h"

#include "ACChatOverlay.h"
#include "MyCheckNull.h"

UACGameInstance::UACGameInstance(const FObjectInitializer& ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UUserWidget> TheMenuClass(TEXT("/Game/UI/WBP_ChatOverlay"));
	MYCHECKNULL(TheMenuClass.Class);
	ChatOverlayClass = TheMenuClass.Class;
}

void UACGameInstance::Init()
{
	Super::Init();
}

void UACGameInstance::LoadChatOverlay()
{
	MYCHECKNULL(ChatOverlayClass);
	UACChatOverlay* ChatOverlay(CreateWidget<UACChatOverlay>(this, ChatOverlayClass));
	MYCHECKNULL(ChatOverlay);
	const auto LocalController = GetFirstLocalPlayerController();
	MYCHECKNULL(LocalController);

	ChatOverlay->AddToViewport();
}

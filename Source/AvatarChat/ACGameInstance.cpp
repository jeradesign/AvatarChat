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
	ChatOverlay = (CreateWidget<UACChatOverlay>(this, ChatOverlayClass));
	MYCHECKNULL(ChatOverlay);
	const auto LocalController = GetFirstLocalPlayerController();
	MYCHECKNULL(LocalController);

	ChatOverlay->AddToViewport();
}

void UACGameInstance::SendMessage(const FString& Message)
{
	ChatOverlay->LogMessage(Message);
}

void UACGameInstance::BeginHosting()
{
	const auto Engine(GetEngine());
	MYCHECKNULL(Engine);

	Engine->AddOnScreenDebugMessage(0, 10.0f, FColor::Green, "Hosting");

	UWorld* World = GetWorld();
	MYCHECKNULL(World);
	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UACGameInstance::JoinServer(const FString& IpAddr)
{
	const auto Engine(GetEngine());
	MYCHECKNULL(Engine);
	const FString Message = "Joining: " + IpAddr;

	Engine->AddOnScreenDebugMessage(0, 10.0f, FColor::Green, Message);

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	MYCHECKNULL(PlayerController);
	PlayerController->ClientTravel(*IpAddr, TRAVEL_Absolute);
}

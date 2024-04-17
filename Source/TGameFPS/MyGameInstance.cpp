// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include"Engine/World.h"
#include"AppManager.h"

UMyGameInstance* __AppGameInstance = nullptr;

void UMyGameInstance::AppInitGameInstance()
{
	auto MyWorld = GetWorld();
	__AppGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

	app::run();

}

int32 UMyGameInstance::GetTimeSeconds()
{
	int32 ftime = GetWorld()->GetTimeSeconds();
	return ftime;
}

void UMyGameInstance::Shutdown()
{
	if(app::__TcpClient != NULL)
	{
		app::__TcpClient->setThread(true);
		app::__TcpClient->disconnectServer(8000, "shutdown");
	}

	Super::Shutdown();
}


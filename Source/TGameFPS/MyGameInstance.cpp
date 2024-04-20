// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include"Engine/World.h"
#include"AppManager.h"

UMyGameInstance* __AppGameInstance = nullptr;


void UMyGameInstance::AppInitGameInstance()
{
	if(GetWorld())
	{
		auto MyWorld = GetWorld();
		__AppGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	}
	else
	{
		FString ss = FString::Printf(TEXT("GetWorld() failure"));
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, ss);//´òÓ¡ÏûÏ¢
		return;
	}
	app::run();

}

void UMyGameInstance::UpdateTimeSecondsManu(float time)
{
	GlobalTimeSeconds = GlobalTimeSeconds + time;
}

float UMyGameInstance::GetTimeSecondsManu()
{
	return GlobalTimeSeconds;
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




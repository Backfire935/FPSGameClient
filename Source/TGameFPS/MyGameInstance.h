// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TGAMEFPS_API  UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	void AppInitGameInstance();

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	void UpdateTimeSecondsManu(float time);//按帧增加时间

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	float GetTimeSecondsManu();

	UFUNCTION(BlueprintImplementableEvent, Category= "MyEngine")
	void onCommand(int cmd);

	UFUNCTION(BlueprintImplementableEvent, Category= "MyEngine")
	void onConnect(int errcode);

	UFUNCTION(BlueprintImplementableEvent, Category= "MyEngine")
	void onSecurity(int errcode);

	UFUNCTION(BlueprintImplementableEvent, Category= "MyEngine")
	void onDisconnect(int errcode);
	
	UFUNCTION(BlueprintImplementableEvent, Category= "MyEngine")
	void onExcept(int errcode);

	virtual void Shutdown();

	float GlobalTimeSeconds = 0;//全局心跳时间
};

extern UMyGameInstance* __AppGameInstance;

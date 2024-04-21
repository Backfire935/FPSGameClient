// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintFunction.generated.h"

#pragma  pack(push,packing)
#pragma  pack(1)

USTRUCT(BlueprintType)
struct FPlayerBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyEngine")
	int32  memid = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyEngine")
	int32 socketfd = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyEngine")
	int32 state = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyEngine")
	int32 curhp = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyEngine")
	int32 maxhp = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyEngine")
	float speed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyEngine")
	FVector pos = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyEngine")
	FRotator rot = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyEngine")
	FString nick = "";

};

USTRUCT(BlueprintType)
struct FRoomSettings//房间设置
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomMode = "";//房间模式
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomMap = "";//房间地图
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	bool bFriendlyDamage = false;//是否开启友伤
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	bool bAddBots = false;//是否添加机器人
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 TeamABotsNum = 0;//A队Bot数量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 TeamBBotsNum = 0;//B队Bot数量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomLevel = "";//关卡难度 || AI难度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 RoomMaxPlayer = 0;//房间最大人数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 RoomCurPlayer = 0;//房间当前人数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 WinTarget = 0;//胜利条件
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoundTime = "";//对局时间
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	int32 RoomID = 0;//房间ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	int32 RoomType = 0;//房间类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	int32 RoomState = 0;//房间状态 是否开始游戏
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	int32 RoomOwner = 0;//房主memID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	FString RoomName = "突破自己";//房间名字
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	FString RoomPassword = "";//房间密码
};

USTRUCT(BlueprintType)
struct FRoomInfo //房间的简易信息
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomMode = "";//房间模式
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomMap = "";//房间地图
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 RoomMaxPlayer = 0;//房间最大人数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 RoomCurPlayer = 0;//房间当前人数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomName = "";//房间名字
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 RoomState = 0;//房间状态 是否开始游戏

};

USTRUCT(BlueprintType)
struct FGameServerInfo//游戏服务器信息
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "GameServerInfo")
	int32 ServerID = 0;//服务器ID
	UPROPERTY(BlueprintReadOnly, Category = "GameServerInfo")
	FString ServerName = "";//服务器名字
	UPROPERTY(BlueprintReadOnly, Category = "GameServerInfo")
	TArray<FRoomInfo> RoomInfos;//所有的房间信息
};


#pragma pack(pop,packing)

/**
 * 
 */
UCLASS()
class TGAMEFPS_API  UBlueprintFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static int32 AppUpdate();

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static int32 disConnect();

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyEngine")
	static bool isSecurity();

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyEngine")
   static int32 read_int8();

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyEngine")
	static int32 read_int16();

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyEngine")
       static int32 read_int32();

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyEngine")
	static float read_float();

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyEngine")
	static bool read_bool();

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyEngine")
	static FVector read_FVector();

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyEngine")
	static FRotator read_FRotator();

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyEngine")
	static FString read_FString_len(int32 len);

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyEngine")
	static FString read_FString();

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyEngine")
	static FPlayerBase read_FPlayerBase();//

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static void send_begin(int32 cmd);

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static void send_end();

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static void send_int8(int32 value);

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static void send_int16(int32 value);

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static void send_int32(int32 value);

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static void send_float(float value);

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static void send_bool(bool value);

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static void send_FVector(FVector value);

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static void send_FRotator(FRotator value);
	
	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static void send_FString_len(FString value, int32 len);

	UFUNCTION(BlueprintCallable, Category = "MyEngine")
	static void send_FString(FString value);

	/// <summary>
	/// 注意这里的函数都是申请获得数据，不是直接获取数据，数据要等待服务器返回从OnCommand里面获取，具体在GameInstance的蓝图里面实现
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "GameServer")
	static void GetAllGameServers();//获取所有的GameServer的情况 获取玩家在线数量,房间数量 即可

	UFUNCTION(BlueprintCallable, Category = "GameServer")
	static void JoinOneGameServer(int PlayerID, int ServerId);//玩家xx加入一个GameServer

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void CreateRoomInGameServer(int PlayerID, int ServerId, FRoomSettings RoomSettings);//玩家xx在xxGameServer创建游戏房间，供其他玩家加入和准备游戏

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void GetAllRoomsInGameServer();//申请获取当前GameServer所有的游戏房间信息

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void JoinRoomInGameServer(int PlayerID, int RoomId);//玩家xx申请加入xx房间

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void LeaveRoomInGameServer(int PlayerID, int RoomId);//玩家xx申请离开xx房间

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void ChangeRoomSettings(int PlayerID, int RoomId, FRoomSettings RoomSettings);//玩家xx申请修改xx房间设置

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void ReadyOrNot(int PlayerID, int RoomId, bool bReady);//玩家准备或者取消准备,如果是房主就申请开始游戏

};

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
struct FRoomSettings//��������
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomMode = "";//����ģʽ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomMap = "";//�����ͼ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	bool bFriendlyDamage = false;//�Ƿ�������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	bool bAddBots = false;//�Ƿ���ӻ�����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 TeamABotsNum = 0;//A��Bot����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 TeamBBotsNum = 0;//B��Bot����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomLevel = "";//�ؿ��Ѷ� || AI�Ѷ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 RoomMaxPlayer = 0;//�����������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 RoomCurPlayer = 0;//���䵱ǰ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 WinTarget = 0;//ʤ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoundTime = "";//�Ծ�ʱ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	int32 RoomID = 0;//����ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	int32 RoomType = 0;//��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	int32 RoomState = 0;//����״̬ �Ƿ�ʼ��Ϸ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	int32 RoomOwner = 0;//����memID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	FString RoomName = "ͻ���Լ�";//��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RoomSettings")
	FString RoomPassword = "";//��������
};

USTRUCT(BlueprintType)
struct FRoomInfo //����ļ�����Ϣ
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomMode = "";//����ģʽ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomMap = "";//�����ͼ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 RoomMaxPlayer = 0;//�����������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 RoomCurPlayer = 0;//���䵱ǰ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	FString RoomName = "";//��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoomSettings")
	int32 RoomState = 0;//����״̬ �Ƿ�ʼ��Ϸ

};

USTRUCT(BlueprintType)
struct FGameServerInfo//��Ϸ��������Ϣ
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "GameServerInfo")
	int32 ServerID = 0;//������ID
	UPROPERTY(BlueprintReadOnly, Category = "GameServerInfo")
	FString ServerName = "";//����������
	UPROPERTY(BlueprintReadOnly, Category = "GameServerInfo")
	TArray<FRoomInfo> RoomInfos;//���еķ�����Ϣ
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
	/// ע������ĺ����������������ݣ�����ֱ�ӻ�ȡ���ݣ�����Ҫ�ȴ����������ش�OnCommand�����ȡ��������GameInstance����ͼ����ʵ��
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "GameServer")
	static void GetAllGameServers();//��ȡ���е�GameServer����� ��ȡ�����������,�������� ����

	UFUNCTION(BlueprintCallable, Category = "GameServer")
	static void JoinOneGameServer(int PlayerID, int ServerId);//���xx����һ��GameServer

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void CreateRoomInGameServer(int PlayerID, int ServerId, FRoomSettings RoomSettings);//���xx��xxGameServer������Ϸ���䣬��������Ҽ����׼����Ϸ

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void GetAllRoomsInGameServer();//�����ȡ��ǰGameServer���е���Ϸ������Ϣ

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void JoinRoomInGameServer(int PlayerID, int RoomId);//���xx�������xx����

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void LeaveRoomInGameServer(int PlayerID, int RoomId);//���xx�����뿪xx����

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void ChangeRoomSettings(int PlayerID, int RoomId, FRoomSettings RoomSettings);//���xx�����޸�xx��������

	UFUNCTION(BlueprintCallable, Category = "CreateGame")
	static void ReadyOrNot(int PlayerID, int RoomId, bool bReady);//���׼������ȡ��׼��,����Ƿ��������뿪ʼ��Ϸ

};

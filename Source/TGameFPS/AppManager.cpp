#include "AppManager.h"
#include"MyGameInstance.h"

namespace app
{
	AppManager* __AppManager = nullptr;
	net::TcpClient* __TcpClient = nullptr;
	
	AppManager::AppManager()
	{
	}

	AppManager::~AppManager()
	{
		
	}

	void onUpdate()
	{
		if (__TcpClient == nullptr) return;
			__TcpClient->parseCommand();
		
	}

	void onConnect(net::TcpClient* tcp, const int32 code)
	{
		__AppGameInstance->onConnect(code);
	
	}

	void onSecurityConnect(net::TcpClient* tcp, const int32 code)
	{
		__AppGameInstance->onSecurity(code);
	
	}

	void onDisconnect(net::TcpClient* tcp, const int32 code)
	{
		__AppGameInstance->onDisconnect(code);
	
	}

	void onExcept(net::TcpClient* tcp, const int32 code)
	{
		__AppGameInstance->onExcept(code);
	
	}

	void onCommand(net::TcpClient* tcp, const int32 code)
	{
		__AppGameInstance->onCommand(code);
	
	}
	
	void InitClientXML()
	{
		if(func::__ClientInfo == nullptr) func::__ClientInfo = new func::ConfigXML();

		func::__ClientInfo->SafeCode = "test";
		func::__ClientInfo->Head[0] = 'D';
		func::__ClientInfo->Head[1] = 'E';
		func::__ClientInfo->RCode = 97;
		func::__ClientInfo->Version = 20231028;
		func::__ClientInfo->ReceOne = 8*1024;
		func::__ClientInfo->ReceMax = 256*1024;
		func::__ClientInfo->SendOne = 8*1024;
		func::__ClientInfo->SendMax = 256*1024;

		func::__ClientInfo->HeartTime = 60;//15��һ������
		func::__ClientInfo->AutoTime = 30;//3��һ���Զ�����

	}
	
	void AppManager::init()
	{
			InitClientXML();
		
			__TcpClient = new net::TcpClient;
			__TcpClient->setOnConnect(onConnect);
			__TcpClient->setOnSecure(onSecurityConnect);
			__TcpClient->setOnDisConnect(onDisconnect);	
			__TcpClient->setOnExcept(onExcept);
			__TcpClient->setOnCommand(onCommand);
		
			__TcpClient->runClient(0, "127.0.0.1",13400);//���ӷ�����
			__TcpClient->getData()->ID = 0;//���ӵ�ʱ��ȥ�����ĸ�������ID

		
	}

	int run()
	{
		if(__AppManager == nullptr)
		{
			__AppManager = new AppManager();
			__AppManager->init();
		}

		app::__TcpClient->setThread(false);//�����̲߳���ͣ
		return 0;
	}
}
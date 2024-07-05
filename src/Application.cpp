#include "Application.h"
#include "base/Config.h"

#include "RealmDC/RealmDC.h"
#include "RealmDC/LinkQQ.h"

#include "RealmQQ/RealmQQ.h"
#include "RealmQQ/LinkDC.h"

namespace Realm {
	//Necessary initialization
	Application* Application::Init(){
		Base::InitConfig("/home/awalwa/projects/ConsoleApplication/date/");

		InitRealmDC();
		InitRealmQQ();

		RealmDC::GetInstance()->DCInit();
		RealmQQ::GetInstance()->QQInit();

		//Link
		DC::LinkQQ::output(QQ::LinkDC::Input);
		QQ::LinkDC::output(DC::LinkQQ::Input);

		return s_Instance;
	}

	//start Run and Execute Funtion,Runing date link
	Application* Application::Run(){
		RealmDC::GetInstance()->DCRun();
		RealmQQ::GetInstance()->QQRun();

		return s_Instance;
	}

	//~Funtion,And Save Run Data
	Application* Application::Quit(){
		RealmDC::GetInstance()->DCQuit();
		RealmQQ::GetInstance()->QQQuit();

		return s_Instance;
	}

	//TODO:User defined
	Application::Application(){

	}

	//Practice Free memory
	Application::~Application(){
		delete s_Instance;
		s_Instance = nullptr;
	}

	//CreateInstance
	Application* Application::CreateApplication(){
		s_Instance = new Application();
		return s_Instance;
	}

	Application* Application::s_Instance = nullptr;
}

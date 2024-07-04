#include "Application.h"
#include "base/Config.h"

#include "RealmDC/RealmDC.h"
#include "RealmQQ/RealmQQ.h"

namespace Realm {
	//Necessary initialization
	Application* Application::Init(){
		Base::InitConfig("/home/awalwa/projects/ConsoleApplication/date/");

		InitRealmDC();
		RealmDC::GetInstance()->DCInit();

		return s_Instance;
	}

	//start Run and Execute Funtion,Runing date link
	Application* Application::Run(){
		RealmDC::GetInstance()->DCRun();
		

		return s_Instance;
	}

	//~Funtion,And Save Run Data
	Application* Application::Quit(){
		RealmDC::GetInstance()->DCQuit();

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

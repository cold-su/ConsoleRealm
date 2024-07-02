#include "Application.h"
#include "base/base.hpp"

namespace Realm {
	//Necessary initialization
	Application* Application::Init(){
		base::Init();

		return s_Instance;
	}

	//start Run and Execute Funtion
	Application* Application::Run(){
		return s_Instance;
	}

	//~Funtion,And Save Run Data
	Application* Application::Quit(){
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

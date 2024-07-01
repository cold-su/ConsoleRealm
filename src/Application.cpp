#include "Application.h"

namespace Realm {
	Application* Application::s_Instance = nullptr;

	//Necessary initialization
	Application* Application::Init()
	{
		return s_Instance;
	}

	//start Run and Execute Funtion
	Application* Application::Run()
	{
		return s_Instance;
	}

	//~Funtion
	Application* Application::Quit()
	{
		return s_Instance;
	}

	//TODO:User defined
	Application::Application()
	{

	}

	//Practice Free memory
	Application::~Application()
	{
		delete s_Instance;
		s_Instance = nullptr;
	}

	//CreateInstance
	Application* Application::CreateApplication()
	{
		s_Instance = &Application();
		return s_Instance;
	}

}

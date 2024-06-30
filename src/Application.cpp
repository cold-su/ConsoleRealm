#include "Application.h"

namespace Realm {
	Application* Application::s_Instance = nullptr;

	Application Application::Init()
	{
		return Application();
	}

	Application Application::Run()
	{
		return Application();
	}

	Application Application::Quit()
	{
		return Application();
	}

	Application::Application()
	{

	}

	Application::~Application()
	{
	}

	Application* Application::CreateApplication()
	{
		s_Instance = &Application();
		return s_Instance;
	}

}

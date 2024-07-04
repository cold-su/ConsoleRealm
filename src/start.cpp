#include "Application.h"
#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, char** argv) {

	Realm::Application::CreateApplication()->Init()->Run()->Quit();

	while (1)
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
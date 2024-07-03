#include "Application.h"
#include <iostream>
#include <thread>

int main(int argc, char** argv) {

	Realm::Application::CreateApplication()->Init()->Run()->Quit();
}
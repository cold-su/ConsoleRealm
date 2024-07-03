#include "Application.h"

int main(int argc, char** argv) {

	//yesh
	Realm::Application::CreateApplication()->Init()->Run()->Quit();
	while (1);
}
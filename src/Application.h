/*这个是作为一个引入的文件
*
*/

#pragma once

int main(int argc, char** argv);

namespace Realm {

	class Application {
	public:
		static Application* Init();
		static Application* Run();
		static Application* Quit();

		Application();
		~Application();
	private:
		static Application* CreateApplication();
		friend int ::main(int argc, char** argv);
		static Application* s_Instance;
	};
}
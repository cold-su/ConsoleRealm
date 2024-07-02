#pragma once
#include <json/value.h>



namespace Base {
	class ConfigRead {
	public:
		ConfigRead();
		
		Json::Value ConfigRe_read();
		static ConfigRead* ConfigReadInit();
	private:
		Json::Value JsonConfig;
		static ConfigRead* s_Instance;
	};

	class ConfigSave {
	public:
		ConfigSave(std::string path);

		static ConfigSave* ConfigSaveInit();
	private:
		std::string ConfigPath;
		static ConfigSave* s_Instance;
	};
}
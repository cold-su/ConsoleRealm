#include "Config.h"
#include <fstream>
#include <json/json.h>

namespace Base {
	ConfigRead* ConfigRead::s_Instance = nullptr;

	ConfigRead::ConfigRead() {

	}

	Json::Value ConfigRead::ConfigRe_read() {

		return Json::Value();
	}

	ConfigRead* ConfigRead::ConfigReadInit() {
		s_Instance = new ConfigRead;
		return s_Instance;
	}

	ConfigSave* ConfigSave::s_Instance = nullptr;

	ConfigSave::ConfigSave(std::string path = "") :ConfigPath(path) {

	}

	ConfigSave* ConfigSave::ConfigSaveInit() {
		s_Instance = new ConfigSave();
		return s_Instance;
	}
}
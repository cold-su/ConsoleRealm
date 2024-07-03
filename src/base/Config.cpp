#include "Config.h"
#include <fstream>
#include <json/json.h>

#include <iostream>

namespace Base {
	RealmConfig::RealmConfig(std::string Path_) :Path(Path_) {
		JsonConfig = (Read(Path + "config.json"));
		std::cout << JsonConfig.asString();
	}
	Json::Value RealmConfig::Read(std::string Path) {
		std::ifstream File(Path);

		if (!File.is_open())
			return -1;

		Json::CharReaderBuilder ReaderBuilder;
		ReaderBuilder["emitUTF8"] = true;//utf8

		Json::Value root;

		std::string strerr;

		if (!Json::parseFromStream(ReaderBuilder, File, &root, &strerr))
			return -1;

		return Json::Value();
	}

	RealmConfig* RealmConfig::SetInstance(RealmConfig* Instance) {
		s_Instance = Instance;
		return s_Instance;
	}

	RealmConfig* RealmConfig::GetInstance(){
		return s_Instance;
	}

	Json::Value* RealmConfig::GetJsonConfig(){
		return &JsonConfig;
	}

	RealmConfig* RealmConfig::s_Instance = nullptr;
	void InitConfig(std::string Path) {
		RealmConfig::SetInstance(new RealmConfig(Path));

	}
}
#include "Config.h"
#include <fstream>
#include <json/json.h>

#include <iostream>

namespace Base {
	RealmConfig::RealmConfig(std::string Path_) :Path(Path_), JsonConfig(Read(Path_ + "config.json")){
	}

	nlohmann::json RealmConfig::Read(std::string Path) {
		std::ifstream File(Path);

		nlohmann::json doc;
		if (!File.is_open()) {
			exit(1);
		}
		File >> doc;
		File.close();

		return doc;
	}

	RealmConfig* RealmConfig::SetInstance(RealmConfig* Instance) {
		s_Instance = Instance;
		return s_Instance;
	}

	RealmConfig* RealmConfig::GetInstance(){
		return s_Instance;
	}

	nlohmann::json* RealmConfig::GetJsonConfig(){
		return &JsonConfig;
	}

	RealmConfig* RealmConfig::s_Instance = nullptr;
	void InitConfig(std::string Path) {
		RealmConfig::SetInstance(new RealmConfig(Path));

	}
}
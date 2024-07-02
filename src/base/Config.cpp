#include "Config.h"
#include <fstream>
#include <json/json.h>

namespace Base {
	RealmConfig::RealmConfig():JsonConfig(Read(PathDate + "config.json")) {

	}
	Json::Value RealmConfig::Read(std::string Path){
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

	RealmConfig* RealmConfig::GetInstance(){
		return s_Instance;
	}

	RealmConfig* RealmConfig::s_Instance = nullptr;
}
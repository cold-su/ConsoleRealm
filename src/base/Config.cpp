#include "Config.h"
#include "Path.h"
#include <fstream>
#include <json/json.h>

namespace Base {
	RealmConfig::RealmConfig()
		:ConfigPath(PathDate + "config.json") {
		JsonConfig = Read();
	}
	Json::Value RealmConfig::Read(){
		std::ifstream File(ConfigPath);

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
}
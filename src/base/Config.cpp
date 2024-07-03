#include "Config.h"
#include <fstream>
#include <json/json.h>

#include <iostream>

namespace Base {
	RealmConfig::RealmConfig(std::string Path_) :Path(Path_), JsonConfig(Read(Path_ + "config.json")){
	}

	Json::Value RealmConfig::Read(std::string Path) {
		std::ifstream File(Path);

		if (!File.is_open()) {
			std::cerr << "cennt open file";
		}

		Json::CharReaderBuilder ReaderBuilder;
		ReaderBuilder["emitUTF8"] = true;//utf8支持，不加这句，utf8的中文字符会编程\uxxx

		Json::Value root;

		//把文件转变为json对象
		std::string strerr;

		if (!Json::parseFromStream(ReaderBuilder, File, &root, &strerr)) {
			std::cerr << "json解析错误" << std::endl;
		}

		return root;
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
#pragma once
#include <json/value.h>

namespace Base {
	class RealmConfig {
	public:
		RealmConfig(std::string Path_);

		static Json::Value Read(std::string Path);
		static RealmConfig* SetInstance(RealmConfig* Instance);
		static RealmConfig* GetInstance();
		Json::Value* GetJsonConfig();
	private:
		Json::Value JsonConfig;
		std::string Path;
		static RealmConfig* s_Instance;
	};
	void InitConfig(std::string Path);
}
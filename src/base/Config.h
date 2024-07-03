#pragma once
#include <json/value.h>

namespace Base {
	class RealmConfig {
	public:
		RealmConfig(std::string Path);

		static Json::Value Read(std::string Path);
		static RealmConfig* SetInstance(RealmConfig* Instance);
	private:
		Json::Value JsonConfig;
		static RealmConfig* s_Instance;
	};
	void InitConfig(std::string Path);
}
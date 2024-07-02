#pragma once
#include <json/value.h>

namespace Base {
	class RealmConfig {
	public:
		RealmConfig();

		Json::Value Read();
	private:
		Json::Value JsonConfig;
		std::string ConfigPath;
		static RealmConfig* s_Instance;
	};
}
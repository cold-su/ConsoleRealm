#pragma once
#include <json/value.h>
#include "Path.h"

namespace Base {
	class RealmConfig {
	public:
		RealmConfig();

		static Json::Value Read(std::string Path);
		static RealmConfig* GetInstance();
	private:
		Json::Value JsonConfig;
		static RealmConfig* s_Instance;
	};
}
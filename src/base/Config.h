#pragma once
#include <nlohmann/json.hpp>

namespace Base {
	class RealmConfig {
	public:
		RealmConfig(std::string Path_);

		static nlohmann::json Read(std::string Path);
		static RealmConfig* SetInstance(RealmConfig* Instance);
		static RealmConfig* GetInstance();
		nlohmann::json* GetJsonConfig();
	private:
		nlohmann::json JsonConfig;
		std::string Path;
		static RealmConfig* s_Instance;
	};
	void InitConfig(std::string Path);
}
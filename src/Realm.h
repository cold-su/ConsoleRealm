#pragma once
#include <json/json.h>
#include <httplib.h>
#include <unordered_map>
#include <dpp/dpp.h>
#include <memory>

namespace Realm {
	class ConsoleRealm {
	public:
		static void Init();

		ConsoleRealm();
		static std::unique_ptr<ConsoleRealm> m_ConsoleRealm;
	};

	class Hash {
	public:
		static std::unique_ptr<std::unordered_map<dpp::snowflake, dpp::snowflake>> SnowfalkeHash;
	};

	class Config {
	public:
		

		static std::string path;
		static Json::Value JsonFile;
	};

	class DiscordRealm {
	public:
		static void Init();

		static std::unique_ptr<dpp::cluster> bot;
	};

	class QQRealm {
	public:

	};
}
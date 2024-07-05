#pragma once

#include <unordered_map>
#include <dpp/dpp.h>

namespace Realm {
	class RealmHashDC {
	public:
		static void InitHash();

		static void AddFuntionHash(std::string Command, void(*Funtion)(dpp::slashcommand_t*));

		static std::unique_ptr<std::unordered_map<std::string, void(*) (dpp::slashcommand_t*)>> FuntionHash;

		static std::unique_ptr<std::unordered_map<dpp::snowflake, int>> channelHash;
	};
}
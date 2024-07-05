#include "RealmHashDC.h"
#include "RealmDC.h"

namespace Realm {
	void RealmHashDC::InitHash() {
		FuntionHash.reset(new std::unordered_map<std::string, void(*) (dpp::slashcommand_t*)>());

		channelHash.reset(new std::unordered_map<dpp::snowflake, int>());

		ImageHash.reset(new std::unordered_map<dpp::snowflake, std::string>());
	}
	void RealmHashDC::AddFuntionHash(std::string Command, void(*Funtion)(dpp::slashcommand_t*)) {
		(*FuntionHash)[Command] = Funtion;
	}

	//static
	std::unique_ptr<std::unordered_map<std::string, void(*) (dpp::slashcommand_t*)>> RealmHashDC::FuntionHash = nullptr;

	std::unique_ptr<std::unordered_map<dpp::snowflake, int>> RealmHashDC::channelHash = nullptr;

	std::unique_ptr<std::unordered_map<dpp::snowflake, std::string>> RealmHashDC::ImageHash = nullptr;
}

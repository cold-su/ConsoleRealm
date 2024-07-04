#include "RealmHash.h"
#include "RealmDC.h"

namespace Realm {
	void RealmHash::InitHash(){
		FuntionHash.reset(new std::unordered_map<std::string, void(*) (dpp::slashcommand_t*)>());
	}
	void RealmHash::AddFuntionHash(std::string Command, void(*Funtion)(dpp::slashcommand_t*)){
		(*FuntionHash)[Command] = Funtion;
	}

	//static
	std::unique_ptr<std::unordered_map<std::string, void(*) (dpp::slashcommand_t*)>> RealmHash::FuntionHash = nullptr;
}

#include "RealmHashQQ.h"
#include "../base/Config.h"

namespace Realm {
	void RealmHashQQ::InitHash() {

		groupHash.reset(new std::unordered_map<dpp::snowflake, dpp::snowflake>());

		for (int i = 0; i < (*Base::RealmConfig::GetJsonConfig())["RealmQQ"]["Link"].size(); ++i) {
			dpp::snowflake QQtmp = (*Base::RealmConfig::GetJsonConfig())["RealmQQ"]["Link"][i];
			dpp::snowflake DCtmp = (*Base::RealmConfig::GetJsonConfig())["RealmDC"]["Link"][i];
			std::cout << DCtmp << ":" << QQtmp << std::endl;
			(*RealmHashQQ::groupHash)[DCtmp] = QQtmp;
		}
	}

	//TODO:add static var
	std::unique_ptr<std::unordered_map<dpp::snowflake, dpp::snowflake>> RealmHashQQ::groupHash;
}

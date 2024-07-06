#include "RealmHashQQ.h"
#include "../base/Config.h"

namespace Realm {
	void RealmHashQQ::InitHash() {

		groupHash.reset(new std::unordered_map<dpp::snowflake, int>());

		for (int i = 0; i < (*Base::RealmConfig::GetJsonConfig())["RealmQQ"]["Link"].size(); ++i) {
			int QQtmp = (*Base::RealmConfig::GetJsonConfig())["RealmQQ"]["Link"][i];
			dpp::snowflake DCtmp = (*Base::RealmConfig::GetJsonConfig())["RealmDC"]["Link"][i];
			(*RealmHashQQ::groupHash)[DCtmp] = QQtmp;
			std::cout << DCtmp << ":" << (*RealmHashQQ::groupHash)[DCtmp] << std::endl;
		}
	}

	int RealmHashQQ::GetGroup(dpp::snowflake _id){
		return (*groupHash)[_id];
	}

	//TODO:add static var
	std::unique_ptr<std::unordered_map<dpp::snowflake, int>> RealmHashQQ::groupHash;

	
}

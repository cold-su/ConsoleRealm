#include "RealmDC.h"

namespace Realm {
	RealmDC::RealmDC() : ConfigDC((*Base::RealmConfig::GetInstance()->GetJsonConfig())["RealmDC"]) {
		RealmBot = new dpp::cluster(ConfigDC["Token"].asString());
	}

	void RealmDC::DCInit() {
		RealmBot->on_log(dpp::utility::cout_logger());

	}

	void RealmDC::DCRun() {


		RealmBot->start(dpp::st_wait);
	}

	void RealmDC::DCQuit() {

	}

	void RealmDC::SetInstance(RealmDC* Instance){
		s_Instance = Instance;
	}

	RealmDC* RealmDC::GetInstance() {
		return s_Instance;
	}

	RealmDC* RealmDC::s_Instance = nullptr;

	void InitRealmDC(){
		RealmDC::SetInstance(new RealmDC());
	}
}

#include "RealmDC.h"
#include "RealmHash.h"
#include "slashcommand.h"

namespace Realm {
	RealmDC::RealmDC() : ConfigDC((*Base::RealmConfig::GetInstance()->GetJsonConfig())["RealmDC"]) {
		RealmBot = new dpp::cluster(ConfigDC["Token"].asString());
	}

	void RealmDC::DCInit() {
		RealmBot->on_log(dpp::utility::cout_logger());
		RealmHash::InitHash();
		Slashcommand::InitSlashcommand();
	}

	void RealmDC::DCRun() {


		RealmBot->start(dpp::st_return);
	}

	void RealmDC::DCQuit() {

	}

	void RealmDC::SetInstance(RealmDC* Instance){
		s_Instance = Instance;
	}

	RealmDC* RealmDC::GetInstance() {
		return s_Instance;
	}

	dpp::cluster* RealmDC::GetRealmBot(){
		return RealmBot;
	}



	RealmDC* RealmDC::s_Instance = nullptr;

	void InitRealmDC(){
		RealmDC::SetInstance(new RealmDC());
	}
}

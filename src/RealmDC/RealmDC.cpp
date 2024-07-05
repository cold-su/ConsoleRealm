#include "RealmDC.h"
#include "RealmHash.h"
#include "slashcommand.h"

namespace Realm {
	RealmDC::RealmDC() : ConfigDC((*Base::RealmConfig::GetInstance()->GetJsonConfig())["RealmDC"]) {
		RealmBot = new dpp::cluster(ConfigDC["Token"], dpp::i_default_intents | dpp::i_message_content);
	}

	void RealmDC::DCInit() {
		RealmBot->on_log(dpp::utility::cout_logger());

		RealmBot->start(dpp::st_return);

		RealmHash::InitHash();

		Slashcommand::InitSlashcommand();
	}

	void RealmDC::DCRun() {


	}

	void RealmDC::DCQuit() {

	}

	void RealmDC::SetInstance(RealmDC* Instance) {
		s_Instance = Instance;
	}

	RealmDC* RealmDC::GetInstance() {
		return s_Instance;
	}

	dpp::cluster* RealmDC::GetRealmBot() {
		return s_Instance->RealmBot;
	}



	RealmDC* RealmDC::s_Instance = nullptr;

	void InitRealmDC() {
		RealmDC::SetInstance(new RealmDC());
	}
}

#include "slashcommand.h"
#include "RealmDC.h"
#include "RealmHash.h"

namespace Realm {
	Slashcommand::Slashcommand() :RealmBot(RealmDC::GetInstance()->GetRealmBot()) {

	}

	void Slashcommand::InitSlashcommand() {
		s_Instance = new Slashcommand();
		s_Instance->LoadSlashcommand();
		RunDeleteSlashcommand();

	}
	void Slashcommand::RunDeleteSlashcommand(){
		delete s_Instance;
		s_Instance = nullptr;
	}

	void Slashcommand::LoadSlashcommand(){
		//写入命令
		RealmBot->on_ready([this](const dpp::ready_t event) {
			if (dpp::run_once<struct register_bot_commands>()) {
				

			}
			});
	}

	void Slashcommand::LoadFuntion(){

	}

	Slashcommand* Slashcommand::s_Instance = nullptr;
}
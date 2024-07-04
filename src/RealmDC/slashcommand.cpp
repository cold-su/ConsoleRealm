#include "slashcommand.h"
#include "RealmDC.h"
#include "RealmHash.h"

namespace Realm {
	Slashcommand::Slashcommand() :RealmBot(RealmDC::GetInstance()->GetRealmBot()) {

	}

	void Slashcommand::InitSlashcommand() {
		s_Instance = new Slashcommand();

		s_Instance->LoadSlashcommand();
		s_Instance->LoadSlashcommandFuntion();

		RunDeleteSlashcommand();
	}
	void Slashcommand::RunDeleteSlashcommand() {
		delete s_Instance;
		s_Instance = nullptr;
	}

	void Slashcommand::LoadSlashcommand() {
		//写入命令
		RealmBot->on_ready([this](const dpp::ready_t event) {
			if (dpp::run_once<struct register_bot_commands>()) {
				RealmBot->global_command_create(dpp::slashcommand("Ping", "Test slashcommand", RealmBot->me.id));
			}
			});
	}

	//实现
	void Slashcommand::LoadSlashcommandFuntion() {
		//main
		RealmBot->on_slashcommand([](dpp::slashcommand_t event) {
			try {
				(*RealmHash::FuntionHash)[event.command.get_command_name()](&event);
			}
			catch (const char* msg) {
				std::cerr << "似乎调用了未注册的命令:";
				std::cerr << msg << std::endl;
			}

			
			});
	}

	Slashcommand* Slashcommand::s_Instance = nullptr;
}
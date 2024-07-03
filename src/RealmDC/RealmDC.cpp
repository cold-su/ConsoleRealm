#include "RealmDC.h"

namespace Realm {
	RealmDC::RealmDC() : ConfigDC((*Base::RealmConfig::GetInstance()->GetJsonConfig())["RealmDC"]) {
		RealmBot = new dpp::cluster(ConfigDC["Token"].asString());
	}

	void RealmDC::DCInit() {
		RealmBot->on_log(dpp::utility::cout_logger());

		//test temp
		RealmBot->on_slashcommand([](const dpp::slashcommand_t& event) {
			if (event.command.get_command_name() == "ping") {
				event.reply("Pong!");
			}
			});

		RealmBot->on_ready([this](const dpp::ready_t& event) {
			if (dpp::run_once<struct register_bot_commands>()) {
				RealmBot->global_command_create(dpp::slashcommand("ping", "Ping pong!", RealmBot->me.id));
			}
			});
		//testend
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

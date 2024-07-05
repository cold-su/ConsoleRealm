#include "webhook.h"
#include "../base/Config.h"

namespace Realm {
	Webhook::Webhook() :Linkhook("https://discord.com/api/webhooks/1240743710728257546/GLEkJhhq_QHzXflAZYmekb8ksmt88WfrLE6XybislVY4TVorsimZCn5zEaSdpgdZnom8"){

	}
	void Webhook::InitWebhook(){
		s_Instance = new Webhook();
	}
	dpp::webhook* Webhook::GetWebhook(){
		return &s_Instance->Linkhook;
	}
	void Webhook::LinkWebhook(){
		dpp::message msg = dpp::message("meow~");

		RealmDC::GetRealmBot()->execute_webhook_sync(*GetWebhook(), msg);
		//RealmDC::GetRealmBot()->create_webhook(*GetWebhook());

		std::cout << GetWebhook()->to_json() << std::endl;
	}

	Webhook* Webhook::s_Instance = nullptr;
}

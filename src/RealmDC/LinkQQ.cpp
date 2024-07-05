#include "LinkQQ.h"

#include "RealmHashDC.h"
#include <stdlib.h>

namespace Realm::DC {
	void LinkQQ::InitLink() {

	}
	//输入进DC消息
	void LinkQQ::InputMsg(nlohmann::json obj) {
		Webhook::ObjJS = obj;
		Webhook::LinkWebhook();
	}

	//输出QQ
	void LinkQQ::OutputMsg(void(*Send)(nlohmann::json obj)) {
		RealmDC::GetRealmBot()->on_message_create([Send](const dpp::message_create_t& event) {
			if (event.msg.author.id == 1258868636953608305)
				return;

			nlohmann::json JsonObj = (nlohmann::json)event.msg.to_json();

			JsonObj["usernamecustom"] = event.msg.author.global_name != "" ? event.msg.author.global_name : (std::string)JsonObj["username"];

			//debug
			std::cout << JsonObj << std::endl;

			if (event.msg.channel_id == 950402907575054336)
				(*Send)(JsonObj);
			});
	}

}
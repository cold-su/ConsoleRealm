#include "LinkQQ.h"
#include "RealmDC.h"
#include "RealmHashDC.h"
#include "webhook.h"

namespace Realm::DC {
	void LinkQQ::InitLink() {

	}
	//输入进DC消息
	void LinkQQ::Input(nlohmann::json obj) {
		//debug
		std::cout << "DC函数回调" << std::endl;
		int test = obj["group_id"];
		std::cout << test << std::endl;

		//dpp::message msg;
		//RealmDC::GetRealmBot()->message_create(msg);

		Webhook::LinkWebhook();
	}

	//输出QQ
	void LinkQQ::output(void(*Send)(nlohmann::json obj)) {
		RealmDC::GetRealmBot()->on_message_create([Send](const dpp::message_create_t& event) {

			nlohmann::json JsonObj = (nlohmann::json)event.msg.to_json();

			JsonObj["usernamecustom"] = event.msg.author.global_name != "" ? event.msg.author.global_name : (std::string)JsonObj["username"];

			//debug
			std::cout << JsonObj << std::endl;

			if (event.msg.channel_id == 950402907575054336)
				(*Send)(JsonObj);
			});
	}

}
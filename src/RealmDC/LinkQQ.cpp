#include "LinkQQ.h"
#include "RealmDC.h"
#include "RealmHash.h"

namespace Realm::DC {
	void LinkQQ::InitLink() {

	}
	//输入进DC消息
	void LinkQQ::Input(nlohmann::json obj) {
		//debug
		std::cout << "DC函数回调" << std::endl;

		dpp::message msg;

		RealmDC::GetRealmBot()->message_create(msg);
	}

	//输出QQ
	void LinkQQ::output(void(*Send)(nlohmann::json obj)) {
		RealmDC::GetRealmBot()->on_message_create([Send](const dpp::message_create_t& event) {
			
			static nlohmann::json JsonObj = (nlohmann::json)event.msg.to_json();
			JsonObj["usernamecustom"] = event.msg.author.global_name;

			//debug
			std::cout << JsonObj << std::endl;

			(*Send)((nlohmann::json)event.msg.build_json());
			});
	}

}
#include "LinkQQ.h"

#include "RealmDC.h"
#include "RealmHashDC.h"
#include "../RealmQQ/RealmHashQQ.h"
#include <stdlib.h>

namespace Realm::DC {
	void LinkQQ::InitLink() {

	}
	//输入进DC消息
	void LinkQQ::InputMsg(nlohmann::json obj) {
		ObjJS = obj;
		//add QQ message
		dpp::embed EmbedQQ;



		RealmDC::GetRealmBot()->message_create(dpp::message(RealmHashDC::GetChannel(obj[""]), EmbedQQ));
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

			if (RealmHashQQ::GetGroup(event.msg.channel_id) != NULL)
				(*Send)(JsonObj);
			});
	}

	nlohmann::json LinkQQ::GetObjJS(){
		return ObjJS;
	}

	nlohmann::json DC::ObjJS;
}
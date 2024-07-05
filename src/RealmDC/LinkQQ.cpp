#include "LinkQQ.h"
#include "RealmDC.h"
#include "RealmHash.h"

namespace Realm::DC {
	void LinkQQ::InitLink(){

	}
	//输入进DC消息
	void LinkQQ::Input(nlohmann::json obj){
		dpp::message msg;
		
		RealmDC::GetRealmBot()->message_create(msg);
	}

	//输出QQ
	void LinkQQ::output(void(*Send)(nlohmann::json obj)){
		RealmDC::GetRealmBot()->on_message_create([Send](const dpp::message_create_t event) {
			//debug
			std::cout << event.msg.build_json() << std::endl;

			Send(event.msg.build_json());
			});
	}

}
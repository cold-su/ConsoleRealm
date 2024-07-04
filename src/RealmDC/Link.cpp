#include "Link.h"
#include "RealmDC.h"
#include "RealmHash.h"

namespace Realm::DC {
	void Link::InitLink(){

	}
	//输入进DC消息
	void Link::Input(Json::Value obj){
		dpp::message msg;
		
		RealmDC::GetRealmBot()->message_create(msg);
	}

	//输出QQ
	void Link::output(void(*Send)(Json::Value obj)){
		RealmDC::GetRealmBot()->on_message_create([Send](const dpp::message_create_t event) {
			//debug
			std::cout << event.msg.build_json() << std::endl;

			Send(event.msg.build_json());
			});
	}

	//Link* Link::s_Instance = nullptr;
}
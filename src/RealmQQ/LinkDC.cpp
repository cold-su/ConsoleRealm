#include "LinkDC.h"
#include "RealmQQ.h"

#include <iostream>

namespace Realm::QQ {
	void LinkDC::InitLink(){

	}
	void LinkDC::InputMsg(nlohmann::json obj){
		std::cout << "QQ函数回调" << std::endl;

		RealmQQ::GetRealmBot()->getApiSet().sendGroupMsg(638380392, ((std::string)obj["usernamecustom"] + ":" + (std::string)obj["content"]));
	}

	void LinkDC::OutputMsg(void(*Send)(nlohmann::json obj)){
		RealmQQ::GetRealmBot()->onEvent<twobot::Event::GroupMsg>([Send](const twobot::Event::GroupMsg& msg) {
			//debug
			std::cout << msg.raw_msg << std::endl;

			(*Send)(msg.raw_msg);
			});

	}
}

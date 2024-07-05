#include "LinkDC.h"
#include "RealmQQ.h"

#include "RealmHashQQ.h"
#include <iostream>

namespace Realm::QQ {
	void LinkDC::InitLink() {

	}
	void LinkDC::InputMsg(nlohmann::json obj) {
		std::cout << "QQ函数回调" << std::endl;

		std::cout << (*RealmHashQQ::groupHash)[950402907575054336] << std::endl;
		//TODO:bug
		//int group = (*RealmHashQQ::groupHash)[950402907575054336];

		RealmQQ::GetRealmBot()->getApiSet().
			sendGroupMsg((*RealmHashQQ::groupHash)[950402907575054336], ((std::string)obj["usernamecustom"] + ":" + (std::string)obj["content"]));
	}

	void LinkDC::OutputMsg(void(*Send)(nlohmann::json obj)) {
		RealmQQ::GetRealmBot()->onEvent<twobot::Event::GroupMsg>([Send](const twobot::Event::GroupMsg& msg) {
			//debug
			std::cout << msg.raw_msg << std::endl;

			(*Send)(msg.raw_msg);
			});

	}
}

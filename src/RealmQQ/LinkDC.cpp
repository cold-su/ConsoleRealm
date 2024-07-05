#include "LinkDC.h"
#include "RealmQQ.h"

#include "RealmHashQQ.h"
#include <iostream>
#include <stdlib.h>

namespace Realm::QQ {
	void LinkDC::InitLink() {

	}
	void LinkDC::InputMsg(nlohmann::json obj) {
		std::cout << "QQ函数回调" << std::endl;

		std::cout << (*RealmHashQQ::groupHash)[atoi(std::string(obj["channel_id"]).c_str())] << std::endl;
		//TODO:bug
		int group = (*RealmHashQQ::groupHash)[atoi(std::string(obj["channel_id"]).c_str())];

		RealmQQ::GetRealmBot()->getApiSet().
			sendGroupMsg(group, ((std::string)obj["usernamecustom"] + ":" + (std::string)obj["content"]));
	}

	void LinkDC::OutputMsg(void(*Send)(nlohmann::json obj)) {
		RealmQQ::GetRealmBot()->onEvent<twobot::Event::GroupMsg>([Send](const twobot::Event::GroupMsg& msg) {
			//debug
			std::cout << msg.raw_msg << std::endl;

			(*Send)(msg.raw_msg);
			});

	}
}

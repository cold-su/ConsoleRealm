#include "LinkDC.h"
#include "RealmQQ.h"

#include "RealmHashQQ.h"
#include <iostream>
#include <sstream>
#include <string>

namespace Realm::QQ {
	void LinkDC::InitLink() {

	}
	void LinkDC::InputMsg(nlohmann::json obj) {
		std::cout << "QQ函数回调" << std::endl;

		std::string str = std::string(obj["channel_id"]);
		std::stringstream ss(str);
		dpp::snowflake tmp;
		ss >> tmp;

		RealmQQ::GetRealmBot()->getApiSet().
			sendGroupMsg(RealmHashQQ::GetGroup(tmp), ((std::string)obj["usernamecustom"] + ":" + (std::string)obj["content"]));
	}

	void LinkDC::OutputMsg(void(*Send)(nlohmann::json obj)) {
		RealmQQ::GetRealmBot()->onEvent<twobot::Event::GroupMsg>([Send](const twobot::Event::GroupMsg& msg) {
			//debug
			std::cout << msg.raw_msg << std::endl;

			(*Send)(msg.raw_msg);
			});

	}
}

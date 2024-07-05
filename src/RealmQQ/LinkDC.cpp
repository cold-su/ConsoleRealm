#include "LinkDC.h"
#include "RealmQQ.h"

namespace Realm::QQ {
	void LinkDC::InitLink(){

	}
	void LinkDC::Input(nlohmann::json obj){

	}
	void LinkDC::output(void(*Send)(nlohmann::json obj)){
		RealmQQ::GetRealmBot()->onEvent<twobot::Event::GroupMsg>([&](const twobot::Event::GroupMsg& msg) {
			Send(msg.sender);
			});

	}
}

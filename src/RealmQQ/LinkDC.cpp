#include "LinkDC.h"
#include "RealmQQ.h"

#include <iostream>
#include <sstream>
#include <string>
#include "RealmHashQQ.h"

namespace Realm::QQ {
void LinkDC::InitLink() {
    DC::LinkQQ Obj;
    Obj.OutputMsg(InputMsg);
}
void LinkDC::InputMsg(nlohmann::json obj) {
    std::cout << "QQ函数回调" << std::endl;

    std::string str = std::string(obj["channel_id"]);
    std::stringstream ss(str);
    dpp::snowflake tmp;
    ss >> tmp;

    uint64_t target_group = RealmHashQQ::GetGroup(tmp);
    const std::string& message = ((std::string)obj["usernamecustom"] + ":" + (std::string)obj["content"]);

    RealmQQ::GetRealmBot()->getApiSet().sendGroupMsg(target_group, message);
}

void LinkDC::OutputMsg(void (*Send)(nlohmann::json obj)) {
    RealmQQ::GetRealmBot()->onEvent<twobot::Event::GroupMsg>([Send](const twobot::Event::GroupMsg& msg) {

#ifdef DEBUG  // debug
        std::cout << msg.raw_msg << std::endl;
#endif

        (*Send)(msg.raw_msg);
    });
}
void LinkDC::InputRecall(nlohmann::json obj) {
}
void LinkDC::OutRecall(void (*Send)(nlohmann::json obj)) {
}
}  // namespace Realm::QQ

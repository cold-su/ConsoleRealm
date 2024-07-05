#include "RealmQQ.h"
#include "../base/Config.h"

namespace Realm {
	RealmQQ::RealmQQ() :ConfigQQ((*Base::RealmConfig::GetInstance()->GetJsonConfig())["RealmQQ"]) {
		using twobot::Config;
		using twobot::BotInstance;
		using twobot::ApiSet;
		using namespace twobot::Event;

		// 解决UTF8编码，中文乱码问题，不需要可以不加
		// system("chcp 65001 && cls");

		RealmBot = BotInstance::createInstance(Config{
			"127.0.0.1",
			8080,
			8081,
			std::nullopt
			});
	}
	//加载
	void RealmQQ::QQInit() {

	}
	void RealmQQ::QQRun() {

	}
	//?
	void RealmQQ::QQQuit() {

	}
	void RealmQQ::SetInstance(RealmQQ* Instance) {
		s_Instance = Instance;
	}
	RealmQQ* RealmQQ::GetInstance() {
		return s_Instance;
	}
	RealmQQ* RealmQQ::s_Instance = nullptr;

	void InitRealmQQ() {
		RealmQQ::SetInstance(new RealmQQ);
	}
}
#include "RealmQQ.h"
#include "../base/Config.h"

namespace Realm {
	RealmQQ::RealmQQ() :ConfigDC((*Base::RealmConfig::GetInstance()->GetJsonConfig())["RealmQQ"]) {

	}
	//加载
	void RealmQQ::DCInit() {

	}
	void RealmQQ::DCRun() {

	}
	void RealmQQ::DCQuit() {

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
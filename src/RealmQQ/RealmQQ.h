#pragma once

#include <json/json.h>

namespace Realm {
	class RealmQQ {
	public:
		RealmQQ();

		void DCInit();
		void DCRun();
		void DCQuit();
		static void SetInstance(RealmQQ* Instance);
		static RealmQQ* GetInstance();
	private:
		Json::Value ConfigDC;
		static RealmQQ* s_Instance;
	};
	void InitRealmQQ();
}
#pragma once
#include <dpp/dpp.h>
#include <json/value.h>
#include "../base/Config.h"

namespace Realm {
	class RealmDC {
	public:
		RealmDC();

		void DCInit();
		void DCRun();
		void DCQuit();
		static void SetInstance(RealmDC* Instance);
		static RealmDC* GetInstance();
		dpp::cluster* GetRealmBot();

	private:
		Json::Value ConfigDC;
		dpp::cluster* RealmBot = nullptr;
		static RealmDC* s_Instance;
	};
	void InitRealmDC();
}
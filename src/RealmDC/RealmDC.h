#pragma once
#include <dpp/dpp.h>
#include <nlohmann/json.hpp>

namespace Realm {
	class RealmDC {
	public:
		RealmDC();

		void DCInit();
		void DCRun();
		void DCQuit();
		static void SetInstance(RealmDC* Instance);
		static RealmDC* GetInstance();
		static dpp::cluster* GetRealmBot();

	private:
		nlohmann::json ConfigDC;
		dpp::cluster* RealmBot = nullptr;
		static RealmDC* s_Instance;
	};
	void InitRealmDC();
}
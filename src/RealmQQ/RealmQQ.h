﻿#pragma once

#include <json/json.h>
#include "twobot/twobot.hh"

namespace Realm {
	class RealmQQ {
	public:
		RealmQQ();

		void QQInit();
		void QQRun();
		void QQQuit();
		static void SetInstance(RealmQQ* Instance);
		static RealmQQ* GetInstance();
		static twobot::BotInstance* GetRealmBot();
	private:
		nlohmann::json ConfigQQ;
		std::unique_ptr<twobot::BotInstance> RealmBot;

		static RealmQQ* s_Instance;
	};
	void InitRealmQQ();
}
#pragma once
#include <nlohmann/json.hpp>

#include "RealmDC.h"
#include "RealmHashDC.h"
#include "webhook.h"

namespace Realm::DC {
	class LinkQQ {
	public:
		static void InitLink();
		static void InputMsg(nlohmann::json obj);
		static void OutputMsg(void(*Send)(nlohmann::json obj));

	private:

		//static Link* s_Instance;
	};
}
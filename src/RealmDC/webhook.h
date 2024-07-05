#pragma once

#include <dpp/dpp.h>
#include <nlohmann/json.hpp>

#include "RealmDC.h"

namespace Realm {
	class Webhook {
	public:
		Webhook();

		static void InitWebhook();
		static dpp::webhook* GetWebhook();
		//static Webhook* SetWebhook();
		static void LinkWebhook();
	private:
		dpp::webhook Linkhook;
		static Webhook* s_Instance;
	};
}
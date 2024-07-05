#pragma once

#include <dpp/dpp.h>
#include <httplib.h>
#include "RealmDC.h"

namespace Realm {
	class Webhook {
	public:
		Webhook();

		static void InitWebhook();
		static Webhook* GetWebhook();
	private:
		//httplib::Client a;
		static Webhook* s_Instance;
	};
}
#include "webhook.h"
#include "../base/Config.h"
#include <nlohmann/json.hpp>

namespace Realm {
	Webhook::Webhook() {

	}
	void Webhook::InitWebhook(){
		s_Instance = new Webhook();
	}
	Webhook* Webhook::GetWebhook(){
		return s_Instance;
	}
}

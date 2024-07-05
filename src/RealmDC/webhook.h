#pragma once

#include <dpp/dpp.h>
#include <nlohmann/json.hpp>
#include <curl/curl.h>

#include "RealmDC.h"

namespace Realm {
	class Webhook {
	public:
		Webhook();

		static void InitWebhook();
		static dpp::webhook* GetWebhook();
		//static Webhook* SetWebhook();
		static void LinkWebhook();
		static std::string GetImageHash(nlohmann::json ObjJS);
		static std::string GetImage(dpp::snowflake user_id);

		static nlohmann::json ObjJS;
	private:
		static size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream) {
			size_t written = size * nmemb;
			downloadedData.append(static_cast<char*>(ptr), written);
			return written;
		}
		static std::string downloadedData;

		dpp::webhook Linkhook;
		static Webhook* s_Instance;
	};
}
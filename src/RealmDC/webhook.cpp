#include "webhook.h"
#include "../base/Config.h"
#include "RealmHashDC.h"

namespace Realm {
	Webhook::Webhook() :Linkhook((*Base::RealmConfig::GetInstance()->GetJsonConfig())["Webhook"]["url"]) {

	}
	void Webhook::InitWebhook() {
		s_Instance = new Webhook();
	}
	dpp::webhook* Webhook::GetWebhook() {
		return &s_Instance->Linkhook;
	}
	void Webhook::LinkWebhook() {

		//dpp::webhook w = *Webhook::GetWebhook();
		dpp::webhook w = *GetWebhook();

		//需要内存地址

		w.load_image(GetImageHash(ObjJS), dpp::i_jpg);

		w.name = ObjJS["sender"]["card"] == "" ? ObjJS["sender"]["nickname"] : ObjJS["sender"]["card"];

		std::cout << w.to_json() << std::endl;

		RealmDC::GetRealmBot()->execute_webhook_sync(w, dpp::message(ObjJS["raw_message"]));
	}

	std::string Webhook::GetImageHash(nlohmann::json ObjJS) {
		if ((*RealmHashDC::ImageHash)[ObjJS["group_id"]] == "") {
			(*RealmHashDC::ImageHash)[ObjJS["group_id"]] = GetImage(ObjJS["user_id"]);

			std::cout << ObjJS["user_id"] << std::endl;
			std::cout << (*RealmHashDC::ImageHash)[ObjJS["group_id"]] << std::endl;

			return (*RealmHashDC::ImageHash)[ObjJS["group_id"]];
		}
		else
			return (*RealmHashDC::ImageHash)[ObjJS["group_id"]];
	}

	std::string Webhook::GetImage(dpp::snowflake user_id) {
		std::string image_url = "https://qlogo4.store.qq.com/qzone/";;
		image_url += user_id.str() + "/" + user_id.str() + "/100";

		std::cout << image_url << std::endl;

		CURL* curl;
		CURLcode res;

		curl_global_init(CURL_GLOBAL_DEFAULT);
		curl = curl_easy_init();

		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, image_url.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

			res = curl_easy_perform(curl);
			if (res != CURLE_OK) {
				std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
			}

			curl_easy_cleanup(curl);
		}

		curl_global_cleanup();

		std::cout << "Downloaded data length: " << downloadedData.length() << std::endl;
		return downloadedData;
	}
	nlohmann::json Webhook::ObjJS = nlohmann::json();

	std::string Webhook::downloadedData = std::string();

	Webhook* Webhook::s_Instance = nullptr;
}
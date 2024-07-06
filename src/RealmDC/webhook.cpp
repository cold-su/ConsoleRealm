#include "webhook.h"
#include "../base/Config.h"
#include "RealmHashDC.h"

namespace Realm {
	Webhook::Webhook() :Linkhook((*Base::RealmConfig::GetJsonConfig())["Webhook"]["url"]) {

	}
	void Webhook::InitWebhook() {
		s_Instance = new Webhook();
	}
	dpp::webhook* Webhook::GetWebhook() {
		return &s_Instance->Linkhook;
	}
	void Webhook::LinkWebhook() {
		dpp::webhook webhook = *GetWebhook();

		webhook.load_image(GetImageHash(ObjJS), dpp::i_webp);

		webhook.name = ObjJS["sender"]["card"] == "" ? ObjJS["sender"]["nickname"] : ObjJS["sender"]["card"];

		dpp::snowflake Thread_id = GetChannel(ObjJS["group_id"]);

		//message add
		std::vector<std::string> msgs;

		for (nlohmann::json tmp : ObjJS["message"])
			msgs.push_back(tmp["type"] == "text" ? tmp["data"]["text"] : tmp["data"]["url"]);



		for (std::string msg : msgs) {
			RealmDC::GetRealmBot()->execute_webhook_sync(webhook, dpp::message(msg), false, Thread_id);
		}

	}

	std::string Webhook::GetImageHash(nlohmann::json ObjJS) {
		if ((*RealmHashDC::ImageHash)[ObjJS["group_id"]] == "") {
			(*RealmHashDC::ImageHash)[ObjJS["group_id"]] = GetImage(ObjJS["user_id"]);

			return (*RealmHashDC::ImageHash)[ObjJS["group_id"]];
		}
		else
			return (*RealmHashDC::ImageHash)[ObjJS["group_id"]];
	}

	std::string Webhook::GetImage(dpp::snowflake user_id) {
		std::string image_url = "http://q.qlogo.cn/headimg_dl?dst_uin=";
		image_url += user_id.str() + "&spec=4&img_type=webp";

		std::cout << image_url << std::endl;

		CURL* curl;
		CURLcode res;

		curl_global_init(CURL_GLOBAL_DEFAULT);
		curl = curl_easy_init();

		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, "http://q.qlogo.cn/headimg_dl?dst_uin=822438291&spec=4&img_type=webp");
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
	dpp::snowflake Webhook::GetChannel(dpp::snowflake _id) {
		return (*RealmHashDC::channelHash)[_id];
	}
	nlohmann::json Webhook::ObjJS = nlohmann::json();

	std::string Webhook::downloadedData = std::string();

	Webhook* Webhook::s_Instance = nullptr;
}
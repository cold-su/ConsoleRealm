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
		dpp::webhook w = *GetWebhook();

		w.load_image(GetImageHash(ObjJS), dpp::i_png);

		w.name = ObjJS["sender"]["card"] == "" ? ObjJS["sender"]["nickname"] : ObjJS["sender"]["card"];


		//dpp::webhook whtest((*Base::RealmConfig::GetJsonConfig())["Webhook"]["url"]);
		//nlohmann::json test;

		//test["avatar_url"] = "https://qlogo4.store.qq.com/qzone/822438291/822438291/100";
		//test["name"] = ObjJS["sender"]["card"] == "" ? ObjJS["sender"]["nickname"] : ObjJS["sender"]["card"];

		//whtest.fill_from_json(&test);

		RealmDC::GetRealmBot()->execute_webhook_sync(w, dpp::message(ObjJS["raw_message"]));

		std::cout << w.to_json() << std::endl;
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
		std::string image_url = "http://q.qlogo.cn/headimg_dl?dst_uin=";
		image_url += user_id.str() + "&spec=4&img_type=png";

		std::cout << image_url << std::endl;

		CURL* curl;
		CURLcode res;

		curl_global_init(CURL_GLOBAL_DEFAULT);
		curl = curl_easy_init();

		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, "http://q.qlogo.cn/headimg_dl?dst_uin=822438291&spec=4&img_type=png");
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
	dpp::snowflake Webhook::GetChannel(dpp::snowflake _id){
		return (*RealmHashDC::channelHash)[_id];
	}
	nlohmann::json Webhook::ObjJS = nlohmann::json();

	std::string Webhook::downloadedData = std::string();

	Webhook* Webhook::s_Instance = nullptr;
}
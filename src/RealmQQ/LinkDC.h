#pragma once
#include <nlohmann/json.hpp>
#include "../RealmDC/LinkQQ.h"

namespace Realm::QQ {
	class LinkDC {
	public:
		static void InitLink();

		static void InputMsg(nlohmann::json obj);
		static void OutputMsg(void(*Send)(nlohmann::json obj));

		//static void InputRecall();
		//static void OutRecall();
	private:

		//static Link* s_Instance;
	};
}
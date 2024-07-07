#pragma once
#include <nlohmann/json.hpp>

#include "RealmHashDC.h"


namespace Realm::DC {
	class LinkQQ {
	public:
		static void InitLink();
		static void InputMsg(nlohmann::json obj);
		static void OutputMsg(void(*Send)(nlohmann::json obj));
		static nlohmann::json GetObjJS();
	private:
		static nlohmann::json ObjJS;
		//static Link* s_Instance;
	};
}
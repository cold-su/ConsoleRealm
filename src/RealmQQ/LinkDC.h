#pragma once
#include <nlohmann/json.hpp>

namespace Realm::QQ {
	class LinkDC {
	public:
		static void InitLink();
		static void InputMsg(nlohmann::json obj);
		static void OutputMsg(void(*Send)(nlohmann::json obj));

	private:

		//static Link* s_Instance;
	};
}
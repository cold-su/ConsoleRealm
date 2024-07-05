#pragma once
#include <nlohmann/json.hpp>

namespace Realm::QQ {
	class LinkDC {
	public:
		static void InitLink();
		static void Input(nlohmann::json obj);
		static void output(void(*Send)(nlohmann::json obj));

	private:

		//static Link* s_Instance;
	};
}
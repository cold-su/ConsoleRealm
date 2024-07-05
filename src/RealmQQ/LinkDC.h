#pragma once
#include <json/value.h>

namespace Realm::QQ {
	class LinkDC {
	public:
		static void InitLink();
		static void Input(Json::Value obj);
		static void output(void(*Send)(Json::Value obj));

	private:

		//static Link* s_Instance;
	};
}
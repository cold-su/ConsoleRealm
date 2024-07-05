#pragma once
#include <json/value.h>
namespace Realm::DC {
	class LinkQQ {
	public:
		static void InitLink();
		static void Input(Json::Value obj);
		static void output(void(*Send)(Json::Value obj));

	private:

		//static Link* s_Instance;
	};
}
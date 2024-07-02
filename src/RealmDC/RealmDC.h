#pragma once
#include <dpp/dpp.h>
#include "../base/Path.h"

class RealmDC {
public:
	RealmDC();

private:
	dpp::cluster Realm = dpp::cluster(JsonConfig["RealmDC"]["Token"].asString());
	static RealmDC* s_Instance;
};
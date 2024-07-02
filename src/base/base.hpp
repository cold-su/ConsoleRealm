#pragma once
#include "Config.h"

using namespace Base;

namespace base {
	void Init() {
		ConfigRead::ConfigReadInit();
		ConfigSave::ConfigSaveInit();


	}
}
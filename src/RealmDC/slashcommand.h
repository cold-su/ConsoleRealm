#pragma once

#include <dpp/cluster.h>

namespace Realm {
	class Slashcommand {
	public:
		Slashcommand();
		static void InitSlashcommand();
		
	private:
		dpp::cluster* RealmBot;
		static Slashcommand* s_Instance;
	};
}
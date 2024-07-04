#pragma once

#include <dpp/cluster.h>

namespace Realm {
	class Slashcommand {
	public:
		Slashcommand();
		static void InitSlashcommand();
	private:
		static void RunDeleteSlashcommand();
		void LoadSlashcommand();
		void LoadFuntion();

		dpp::cluster* RealmBot;
		static Slashcommand* s_Instance;
	};
}
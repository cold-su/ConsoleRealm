#pragma once

#include <dpp/cluster.h>

namespace Realm {
	class Slashcommand {
	public:
		Slashcommand();
		static void InitSlashcommand();
		static Slashcommand* GetInstance();
	private:
		static void RunDeleteSlashcommand();
		void LoadSlashcommand();
		void LoadSlashcommandFuntion();

		dpp::cluster* RealmBot;
		static Slashcommand* s_Instance;
	};
}
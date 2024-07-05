#pragma once

#include <unordered_map>
#include <memory>
#include "dpp/dpp.h"

namespace Realm {
	class RealmHashQQ {
	public:
		static void InitHash();

		static std::unique_ptr<std::unordered_map<dpp::snowflake, dpp::snowflake>> groupHash;
	};
}
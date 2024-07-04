#pragma once

#include <unordered_map>
#include <dpp/dpp.h>

namespace Realm {
	class RealmHash {
	public:
		static void InitHash();

		static void AddFuntionHash();

		static std::unordered_map<std::string, void* ()> FuntionHash;
	};
}
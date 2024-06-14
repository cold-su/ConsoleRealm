#pragma once
#include "Realm.h"
using namespace Realm;

//ConsoleRealm
std::unique_ptr<ConsoleRealm> ConsoleRealm::m_ConsoleRealm;

//Config
std::string Config::path;
Json::Value Config::JsonFile;

//DiscordRealm
std::unique_ptr<dpp::cluster> DiscordRealm::bot;

//QQRealm


//hash
std::unique_ptr<std::unordered_map<dpp::snowflake, dpp::snowflake>> Hash::SnowfalkeHash = std::unique_ptr<std::unordered_map<dpp::snowflake, dpp::snowflake>>();
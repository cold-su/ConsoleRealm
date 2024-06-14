#include "Realm.h"

using namespace Realm;

void ConsoleRealm::Init(){
	m_ConsoleRealm.reset(new ConsoleRealm());
}

Realm::ConsoleRealm::ConsoleRealm(){

}

void Realm::DiscordRealm::Init() {
	bot.reset(new dpp::cluster(Config::JsonFile["DiscordRealm"]["Token"].asString()));
}
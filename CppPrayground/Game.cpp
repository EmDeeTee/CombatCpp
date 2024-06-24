#include <ranges>

#include "Game.h"
#include "Util.h"
#include "PredefinedEntities.h"

void Game::Notify(std::string msg, bool mustConfirm) {
	printf("%s\n", msg.c_str());
	if (mustConfirm) {
		int _ = getchar();
	}
}

Entity& Game::GenerateEncounter(void) {
	auto kv = std::views::keys(gEntities);
	std::vector<std::string> keys { kv.begin(), kv.end() };	

	return gEntities[keys[(Util::RandomRangeInt(0, gEntities.size()-1))]];
}

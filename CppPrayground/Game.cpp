#include "Game.h"

void Game::Notify(std::string msg, bool mustConfirm) {
	printf("%s\n", msg.c_str());
	if (mustConfirm) {
		int _ = getchar();
	}
}

#include <iostream>

#include "types.h"
#include "Entity.h"
#include "BattleManager.h"
#include "PredefinedEntities.h"
#include "Util.h"
#include "Game.h"
#include "Player.h"

int main() {
	BattleManager br(Game::GenerateEncounter());
	br.StartBattle();
	br.DisplayBattleResult();
}
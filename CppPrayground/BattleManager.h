#pragma once

#include <stdint.h>

#include "types.h"
#include "Entity.h"
#include "BattleResult.h"

class BattleManager {
public:
	BattleResult StartBattle(Entity& enemy);
	void DisplayBattleResult(BattleResult& br);
	void NextTurn(BattleResult& br, Entity& enemy);
};


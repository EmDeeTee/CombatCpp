#pragma once

#include <stdint.h>

#include "types.h"
#include "Entity.h"
#include "BattleResult.h"

class BattleManager {
public:
	BattleManager(const Entity& enemy);
	void StartBattle(void);
	void DisplayBattleResult(void);
	void NextTurn(void);
	hp_t AttackPlayer(void);
	hp_t PlayerAttack(void);
private:
	BattleResult _br = {0};
	Entity _enemy;

	bool _HandleChoice();
};


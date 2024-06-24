#pragma once

#include <stdint.h>
#include <Windows.h>

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
	BattleResult mBr = {0};
	Entity mEnemy;

	bool _HandleChoice(void);
};


#pragma once

#include <stdint.h>
#include <Windows.h>

#include "types.h"
#include "Entity.h"
#include "BattleResult.h"
#include "AttackInfo.h"

class BattleManager {
public:
	BattleManager(const Entity& enemy);
	void StartBattle(void);
	void DisplayBattleResult(void);
	void NextTurn(void);
	AttackInfo Attack(Entity& attacker, Entity& attacked);
private:
	BattleResult mBr = {0};
	Entity mEnemy;

	bool _HandleChoice(void);
};


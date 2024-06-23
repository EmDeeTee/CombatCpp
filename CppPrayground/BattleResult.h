#pragma once

#include <cstdint>

#include "types.h"

struct BattleResult {
	uint16_t hits = 0, turns = 1;
	hp_t damageTaken, damageInflicted;
	bool playerWon;
};

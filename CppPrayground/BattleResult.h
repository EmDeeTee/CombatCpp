#pragma once

#include <cstdint>

#include "types.h"

struct BattleResult {
	// How many hits the player did
	uint16_t hits = 0;
	uint16_t turns = 1;
	// Taken = by the enemy
	// Inflicted = by the player
	hp_t damageTaken;
	hp_t damageInflicted;
	bool playerWon;
};

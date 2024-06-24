#pragma once

#include <iostream>

#include "types.h"

class Entity;

class Spell {
	// TODO: Add a spell that decreases the enemy's speed
public:
	Spell(std::string name, spell_duration_t durationTurns);
	virtual void Cast(Entity& target) { };
	virtual void DeSpell(Entity& target) { };

	spell_duration_t GetDurationLeft(void);
private:
	std::string mName;
	spell_duration_t mDurationTurns;
};


#pragma once
#include <string>
#include <vector>

#include "types.h"
#include "EntityAttributes.h"
#include "InventoryItem.h"
#include "Spell.h"

class Entity {
private:
	hp_t mHp = 0;
	std::vector<InventoryItem> mLoot;
	std::vector<Spell> mActiveSpells;
public:
	std::string mName;
	EntityAttributes mAttrs;

	Entity(const std::string& name, const hp_t& hp, const EntityAttributes& attrs = {1,1,1});
	Entity();
	bool Damage(hp_t points);
	void Heal(hp_t points);
	hp_t GetHP(void) const;
	bool IsAlive(void) const;
	hp_t GetNextAttackDamage(void) const; 
	bool IsPlayer(void) const;
	void ApplySpell(Spell spell);
};


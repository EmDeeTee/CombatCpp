#pragma once
#include <string>
#include <vector>

#include "types.h"
#include "EntityAttributes.h"
#include "InventoryItem.h"

class Entity {
private:
	hp_t mHp = 0;
	std::vector<InventoryItem> mLoot;
public:
	std::string mName;
	EntityAttributes mAttrs;

	Entity(const std::string& name, const hp_t& hp, const EntityAttributes& attrs = {1,1,1});
	Entity();
	bool Damage(hp_t points);
	void Heal(hp_t points);
	hp_t GetHP(void);
	bool IsAlive(void);
	hp_t GetNextAttackDamage(void); 
	bool IsPlayer(void) const;
};


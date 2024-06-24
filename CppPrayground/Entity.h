#pragma once
#include <string>
#include <vector>

#include "types.h"
#include "EntityAttributes.h"
#include "InventoryItem.h"

class Entity {
private:
	hp_t mHp = 0;
protected:
	std::vector<InventoryItem> mLoot;
public:
	std::string mName;
	EntityAttributes mAttrs;

	Entity(std::string name, hp_t hp = 100, EntityAttributes attrs = {1,1,1});
	Entity();
	bool Damage(hp_t points);
	void Heal(hp_t points);
	hp_t GetHP(void);
	bool IsAlive(void);
	hp_t GetNextAttackDamage(void); 
};


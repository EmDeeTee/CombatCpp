#pragma once
#include <string>
#include <vector>

#include "types.h"
#include "EntityAttributes.h"
#include "InventoryItem.h"

class Entity {
private:
	hp_t _hp = 0;
protected:
	std::vector<InventoryItem> _loot;
public:
	std::string m_name;
	EntityAttributes m_attrs;
	Entity(std::string name, hp_t hp = 100);
	bool Damage(hp_t points);
	void Heal(hp_t points);
	hp_t GetHP(void);
	bool IsAlive(void);
	hp_t GetNextAttackDamage(); 
};


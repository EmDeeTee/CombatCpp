#include <algorithm>

#include "Entity.h"

Entity::Entity(std::string name, hp_t hp) {
	m_name = name;
	_hp = hp;
}

/// <summary>
/// Damage the enemy.
/// returns false if the enemy died after the attack
/// otherwise, returns true
/// </summary>
/// <returns></returns>
bool Entity::Damage(hp_t points) {
    if (points >= _hp) {
        _hp = 0;
    }
    else {
        _hp -= points;
    }
    return IsAlive();
}

void Entity::Heal(hp_t points) {
    throw new std::exception("Not implemented");
}

hp_t Entity::GetHP(void) {
    return _hp;
}

// TODO: Later, I could add stuff like necromancy to keep the enemy alive even when 
// he has less than 0 HP
bool Entity::IsAlive(void) {
	return _hp > 0;
}

hp_t Entity::GetNextAttackDamage() {
	return m_attrs.str * 2;
}

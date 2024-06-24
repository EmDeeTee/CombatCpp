#include <algorithm>

#include "Entity.h"
#include "Util.h"
#include "Player.h"

Entity::Entity(const std::string& name, const hp_t& hp, const EntityAttributes& attrs) {
	mName = name;
    mAttrs = attrs;
	mHp = hp;
}

Entity::Entity() {
}

/// <summary>
/// Damage the enemy.
/// returns false if the enemy died after the attack
/// otherwise, returns true
/// </summary>
/// <returns></returns>
bool Entity::Damage(hp_t points) {
    if (points >= mHp) {
        mHp = 0;
    }
    else {
        mHp -= points;
    }
    return IsAlive();
}

void Entity::Heal(hp_t points) {
    throw new std::exception("Not implemented");
}

hp_t Entity::GetHP(void) const {
    return mHp;
}

// TODO: Later, I could add stuff like necromancy to keep the enemy alive even when 
// he has less than 0 HP
bool Entity::IsAlive(void) const {
	return mHp > 0;
}

hp_t Entity::GetNextAttackDamage(void) const {
    hp_t dmg = mAttrs.str * 2;
    return Util::RandomRangeInt(dmg - 1, dmg);
}

bool Entity::IsPlayer(void) const {
    return mName == gPlayer.mName;
}

void Entity::ApplySpell(Spell spell) {
    if (spell.GetDurationLeft() > 0) {
        mActiveSpells.push_back(spell);
    }
    else {
        spell.Cast(*this);
    }
}

#pragma once

#include "types.h"

// NOTE: I'm not including entity HP inside this struct
// my reasoning is: HP isn't a skill, while something like strength is
struct EntityAttributes {
	attr_t str = 1; // How much damage the entity deals and how much HP it has
	attr_t spd = 1; // Who acts first in a battle? Higher speed (spd) always gets the first turn
	attr_t dod = 1; // Dodge
};

inline const uint32_t gcAttrCount = 3;

inline EntityAttributes& operator+=(EntityAttributes& lhs, const EntityAttributes& rhs) {
	static_assert(gcAttrCount == 3, "Not every EntityAttribute was handled in operator overload");

	lhs.str += rhs.str;
	lhs.spd += rhs.spd;
	lhs.dod += rhs.dod;
	return lhs;
}

inline EntityAttributes& operator-=(EntityAttributes& lhs, const EntityAttributes& rhs) {
	static_assert(gcAttrCount == 3, "Not every EntityAttribute was handled in operator overload");

	lhs.str -= rhs.str;
	lhs.spd -= rhs.spd;
	lhs.dod -= rhs.dod;
	return lhs;
}
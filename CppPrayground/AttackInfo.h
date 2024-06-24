#pragma once

#include <iostream>

#include "types.h"

struct AttackInfo {
	hp_t dmg;
	bool wasDodged;
};

inline std::ostream& operator<<(std::ostream& os, const AttackInfo& ai) {
	if (ai.wasDodged) {
		return os << "the attack was dodged";
	}

	return os << ai.dmg;
}

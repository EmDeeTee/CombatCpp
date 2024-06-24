#include "Spell.h"

Spell::Spell(std::string name, spell_duration_t durationTurns) : mName(name), mDurationTurns(durationTurns) {
}

spell_duration_t Spell::GetDurationLeft(void) {
	return mDurationTurns;
}

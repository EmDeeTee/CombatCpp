#pragma once

#include <map>

#include "Spell.h"

inline std::map<std::string, Spell> gSpells {  
	{"fireball", Spell("Fireball", 0, [](){
		
	})},
};


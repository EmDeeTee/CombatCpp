#pragma once

#include <map>

#include "Entity.h"

inline std::map<std::string, Entity> gEntities {
	{"rat", Entity("Rat", 20, EntityAttributes{1,2,2})},
};
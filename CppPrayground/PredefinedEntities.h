#pragma once

#include <map>
#include <memory>

#include "Entity.h"

std::map<std::string, Entity> g_Enities {
	{"rat", Entity("Rat", 20, EntityAttributes{1,2,2})},
};
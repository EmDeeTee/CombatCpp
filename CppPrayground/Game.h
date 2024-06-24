#pragma once

#include <string>

#include "Entity.h"

class Game {
public:
	static void Notify(std::string msg, bool mustConfirm = false);
	static Entity& GenerateEncounter(void);
};


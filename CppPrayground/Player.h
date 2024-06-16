#pragma once

#include "types.h"
#include "Entity.h"
#include "EntityAttributes.h"

class Player : public Entity {
public:
	Player() : Entity("Player", 100) { }
	void ShowInventory(void);
};

extern Player g_player;


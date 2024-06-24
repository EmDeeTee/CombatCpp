#pragma once

#include "types.h"
#include "Entity.h"
#include "EntityAttributes.h"

class Player : public Entity {
public:
	Player() : Entity("Player", 100, {2,1,0}) { }
	void ShowInventory(void);
};

extern Player gPlayer;


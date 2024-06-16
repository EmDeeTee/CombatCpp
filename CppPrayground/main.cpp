#include <iostream>

#include "types.h"
#include "Entity.h"
#include "BattleManager.h"

int main() {
	BattleManager br;
	Entity e("Kokos", 5);
	auto res = br.StartBattle(e);
	br.DisplayBattleResult(res);
}
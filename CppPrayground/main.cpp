#include <iostream>

#include "types.h"
#include "Entity.h"
#include "BattleManager.h"
#include "PredefinedEntities.h"
#include "Util.h"

int main() {
	BattleManager br(g_Enities["rat"]);
	br.StartBattle();
	br.DisplayBattleResult();
}
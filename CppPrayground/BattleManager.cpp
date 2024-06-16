#include <stdio.h>
#include <string.h>
#include <iostream>

#include "BattleManager.h"
#include "Player.h"
#include "Game.h"

// TODO: Add attack rolls based on strength
// TODO: Add speed based initiative
// TODO: Implement dodge functionallity
BattleResult BattleManager::StartBattle(Entity& enemy) {
    BattleResult br = {0};
    printf("You are in a battle with %s!\n", enemy.m_name.c_str());

    while (enemy.IsAlive()) {
        NextTurn(br, enemy);
        
        hp_t dmg = g_player.GetNextAttackDamage();
        enemy.Damage(dmg);
        Game::Notify("You hit " + enemy.m_name + " for " + std::to_string(dmg));
        br.hits++;
        br.damageInflicted += dmg;
        dmg = enemy.GetNextAttackDamage();
        g_player.Damage(dmg);
        Game::Notify("You got hit for " + std::to_string(dmg));
        br.damageTaken += dmg;
        br.rounds++;

        //system("cls"); // NOTE: That's Windows only but whatever
    }
    br.playerWon = true;

    return br;
}

void BattleManager::DisplayBattleResult(BattleResult& br) {
    printf("Battle Result\n");
    printf("You have inflicted %u damage\n", br.damageInflicted);
    printf("You have taken %u damage\n", br.damageTaken);
    printf("You have hit the enemy %u times\n", br.hits);
    printf("\tThis results in an average of %u damage/hit\n", br.damageInflicted / br.hits);
    printf("The battle lasted for %u rounds\n", br.rounds);
}

void BattleManager::NextTurn(BattleResult& br, Entity& enemy) {
    printf("===============================\n");
    printf("%s HP: %u\n", enemy.m_name.c_str(), enemy.GetHP());
    printf("Your HP: %u\n", g_player.GetHP());
    printf("===============================\n");
    printf("What would you like to do?\n1 - Attack with your main weapon\n2 - Cast a spell\n3 - Flee\n");
    
    again:

    int choice = 0;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        break;
    default:
        printf("Not a valid input\n");
        goto again;
        break;
    }
    
    printf("%u\n", choice);
}

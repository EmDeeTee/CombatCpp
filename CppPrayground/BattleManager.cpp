#include <stdio.h>
#include <string.h>
#include <iostream>
#include <format>

#include "BattleManager.h"
#include "Player.h"
#include "Game.h"

BattleManager::BattleManager(const Entity& enemy) : _enemy(enemy) {
}

// TODO: Add speed based initiative
// TODO: Implement dodge functionality
void BattleManager::StartBattle(void) {
    printf("You are in a battle with %s!\n", _enemy.m_name.c_str());

    if (_enemy.m_attrs.spd > g_player.m_attrs.spd) {
        Game::Notify(std::format("The enemy was faster and hits you for {}", AttackPlayer()), true);
    }

    while (_enemy.IsAlive()) {
        NextTurn();
        _br.turns++;
    }
    _br.playerWon = true;
}

void BattleManager::DisplayBattleResult(void) {
    printf("===== Battle Result =====\n");
    printf("You have inflicted %u damage\n", _br.damageInflicted);
    printf("You have taken %u damage\n", _br.damageTaken);
    printf("You have hit the enemy %u times\n", _br.hits);
    printf("\tThis results in an average of %u damage/hit\n", _br.damageInflicted / _br.hits);
    printf("The battle lasted for %u turns\n", _br.turns);
}

void BattleManager::NextTurn() {   
    printf("===============================\n");
    printf("%s HP: %u\n", _enemy.m_name.c_str(), _enemy.GetHP());
    printf("Your HP: %u\n", g_player.GetHP());
    printf("===============================\n");
    printf("What would you like to do?\n1 - Attack with your main weapon\n2 - Cast a spell\n3 - Flee\n");

    while (!_HandleChoice()) {
        ;
    }
}

hp_t BattleManager::AttackPlayer(void) {
    hp_t dmg = _enemy.GetNextAttackDamage(); 
    g_player.Damage(dmg);
    _br.damageTaken += dmg;
    return dmg;
}

hp_t BattleManager::PlayerAttack(void) {
    hp_t dmg = g_player.GetNextAttackDamage();
    _enemy.Damage(dmg);
    _br.hits++;
    _br.damageInflicted += dmg;
    return dmg;
    //Game::Notify("You hit " + _enemy.m_name + " for " + std::to_string(dmg));
}

bool BattleManager::_HandleChoice() {
    int choice = 0;
    std::cin >> choice;

    system("cls"); // NOTE: That's Windows only but whatever

    switch (choice)
    {
    case 1:
        std::cout << "You hit " << _enemy.m_name << " for " << PlayerAttack() << "\n";
        std::cout << "You got hit for " << AttackPlayer() << "\n";
        return true;
    case 2:
        // TODO: Implement
        throw new std::exception("Not implemented");
        break;
    case 3:
        // TODO: Implement
        throw new std::exception("Not implemented");
        break;
    default:
        printf("Not a valid input\n");
        return false;
        break;
    }
}

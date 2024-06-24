#include <stdio.h>
#include <string.h>
#include <iostream>
#include <format>

#include "BattleManager.h"
#include "Player.h"
#include "Game.h"
#include "Util.h"

BattleManager::BattleManager(const Entity& enemy) : mEnemy(enemy) {
}

// TODO: Implement dodge functionality
void BattleManager::StartBattle(void) {
    printf("You are in a battle with %s!\n", mEnemy.mName.c_str());

    if (mEnemy.mAttrs.spd > gPlayer.mAttrs.spd) {
        AttackInfo enemyAttackInfo = Attack(mEnemy, gPlayer);
        if (enemyAttackInfo.wasDodged) {
            Game::Notify("The enemy was faster, but you dodged", true);
        }
        else {
            Game::Notify(std::format("The enemy was faster and hits you for {}", enemyAttackInfo.dmg), true);
        }
    }

    while (mEnemy.IsAlive()) {
        NextTurn();
        mBr.turns++;
    }
    mBr.playerWon = true;
}

void BattleManager::DisplayBattleResult(void) {
    printf("===== Battle Result =====\n");
    printf("You have inflicted %u damage\n", mBr.damageInflicted);
    printf("You have taken %u damage\n", mBr.damageTaken);
    printf("You have hit the enemy %u times\n", mBr.hits);
    printf("\tThis results in an average of %u damage/hit\n", mBr.damageInflicted / mBr.hits);
    printf("The battle lasted for %u turns\n", mBr.turns);
}

void BattleManager::NextTurn(void) {
    printf("===============================\n");
    printf("%s HP: %u\n", mEnemy.mName.c_str(), mEnemy.GetHP());
    printf("Your HP: %u\n", gPlayer.GetHP());
    printf("===============================\n");
    printf("What would you like to do?\n1 - Attack with your main weapon\n2 - Cast a spell\n3 - Flee\n");

    while (!_HandleChoice()) {
        ;
    }
}

AttackInfo BattleManager::Attack(Entity& attacker, Entity& attacked) {
    AttackInfo ret = { 0 };

    if ( (attacked.mAttrs.dod > attacker.mAttrs.spd) && Util::Chance50()) {
        ret.wasDodged = true;
        return ret;
    }

    hp_t dmg = attacker.GetNextAttackDamage();
    attacked.Damage(dmg);

    if (attacker.IsPlayer()) {
        mBr.damageInflicted += dmg;
        mBr.hits++;
    }
    else {
        mBr.damageTaken += dmg;
    }

    ret.dmg = dmg;

    return ret;
}

bool BattleManager::_HandleChoice(void) {
    int choice = 0;
    std::cin >> choice;

    system("cls"); // NOTE: That's Windows only but whatever

    switch (choice)
    {
    case 1:
        std::cout << "You hit " << mEnemy.mName << ": " << Attack(gPlayer, mEnemy) << "\n";
        std::cout << "You got hit: " << Attack(mEnemy, gPlayer) << "\n";
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

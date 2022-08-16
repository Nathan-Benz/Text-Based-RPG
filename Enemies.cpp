#include "Enemies.h"

Character p1;

Enemies::Enemies() {
    currentEnemy = " ";
    int enemyXP = 0, enemyHP = 0, enemyLVL = 0, enemyDMG = 0;

    enemyName = { "Grunt", "Enforcer", "Mage", "Warden", "Head Master" };
    int currentEnemyNames = sizeof(enemyName);

    
    void enemyGenerate();
}

void Enemies::enemyGenerate() {
    std::string temp = " ";
    int num = rand() % 100 + 1;

    if (num >= 0 && num <= 29) {
        temp = enemyName[0];
        enemyHP = 30;
        enemyDMG = 5 * enemyLVL / 1.5;
    }
    else if (num >= 30 && num <= 59) {
        temp = enemyName[1];
        enemyHP = 45;
        enemyDMG = 10 * enemyLVL / 1.5;
    }
    else if (num >= 60 && num <= 74) {
        temp = enemyName[2];
        enemyHP = 20;
        enemyDMG = 20 * enemyLVL / 1.5;
    }
    else if (num >= 75 && num <= 89) {
        temp = enemyName[3];
        enemyHP = 50;
        enemyDMG = 25 * enemyLVL / 1.5;
    }
    else {
        temp = enemyName[4];
        enemyHP = 75;
        enemyDMG = 30 * enemyLVL / 1.5;
    }
    enemyHP = floor(enemyHP + 13 * pow(2, enemyLVL / 8));
    enemyXP = enemyHP;

    currentEnemy = temp;
}
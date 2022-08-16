#pragma once

#include "Header.h"
#include "Character.h"

class Enemies {
public:
	Enemies();

	int enemyXP, enemyHP, enemyLVL, enemyDMG;
	std::string currentEnemy;

	std::vector<std::string> enemyName;
	int currentEnemyNames = sizeof(enemyName);

	void enemyGenerate();
};
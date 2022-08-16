#pragma once

#include "Header.h"

class Character {
public:
	Character();

	std::string name, type;
	std::vector<std::string> playerClass;

	int HP, totalHP, maxHP, heal, playerDMG, baseDMG;

	int lvl, currentXP, baseXP, xp_to_lvl, minLVL, maxLVL;

	void characterCreation();
};


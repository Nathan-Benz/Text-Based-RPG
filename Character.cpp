#include "Character.h"

Character::Character() {
	name = " ";
	type = " ";

	playerClass = {"Sorcerer", "Knight", "Barbarian", "Archer"};

	lvl = 1, HP = 0, totalHP = 0, maxHP, heal = 0, playerDMG = 0, baseDMG = 0;
    currentXP = 0, baseXP = 50, xp_to_lvl = baseXP, minLVL = 1, maxLVL = 100;
}

void Character::characterCreation() {
    int count = 0;

    std::cout << "Enter your name brave traveler: ";
    std::cin >> name;

    name[0] = toupper(name[0]);

    std::cout << "Classes: ";
    std::cout << playerClass[0] << " <-> " << playerClass[1] << " <-> " << playerClass[2] << " <-> " << playerClass[3] << "\n\n";
    std::cout << "Enter your class: ";
    std::cin >> type;

    //Sets first character to upper
    type[0] = toupper(type[0]);

    //Checks if type names a class and give the correct attributes
    if (type == playerClass[0]) {
        baseDMG = 40;
        HP = 60;
    }
    else if (type == playerClass[1]) {
        baseDMG = 20;
        HP = 110;
    }
    else if (type == playerClass[2]) {
        baseDMG = 30;
        HP = 90;
    }
    else if (type == playerClass[3]) {
        baseDMG = 25;
        HP = 80;
    }
    else {
        baseDMG = 23;
        HP = 100;
    }

    std::cout << "\n";
    
    system("cls");
    //Psuedo character laoding
    for (int i = 3; i > count; i--) {
        if (i == 3) {
            std::cout << "Making character.\n";
        }
        if (i == 2) {
            std::cout << "Making character..\n";
        }
        if (i == 1) {
            std::cout << "Making character...\n";
        }

        Sleep(600);
        system("cls");
    }

    totalHP = HP;
    maxHP = totalHP;
}
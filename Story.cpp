#include "Story.h"
#include "Character.h"
#include "Enemies.h"

Character player;
Enemies enemy;

Story::Story() {
    void Start();
    void HUD();
    void Combat();
    void CombatHUD();
    void Moving();
    void lvlUP();
}

void Story::Start() {
    player.characterCreation();
    enemy.enemyGenerate();
}

void Story::HUD() {
    Sleep(500);
    system("cls");
    std::cout << "Name: " << player.name << "\tHealth: " << player.totalHP << "\tLevel: " << player.lvl << "\tClass:" << player.type << "\nXP: " << player.currentXP << "\tXP needed: " << player.xp_to_lvl << std::endl;

    Moving();
}

void Story::CombatHUD() {
    Sleep(500);
    system("cls");
    std::cout << "Name: " << player.name << "\t|\tEnemy: " << enemy.currentEnemy << "\nHP: " << player.totalHP << "\t\t|\tEnemy HP: " << enemy.enemyHP << "\nLVL: " << player.lvl << "\t\t|\tEnemy LVL: " << enemy.enemyLVL << std::endl;
}

void Story::Combat() {
    CombatHUD();
    int playerATK;



    if (player.totalHP >= 1 && enemy.enemyHP >= 1) {
        std::cout << "\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Block\n";
        std::cout << "3. Escape!\n";
        std::cout << "\n";
        std::cin >> playerATK;

        //Attack
        if (playerATK == 1) {
            player.playerDMG = player.baseDMG * player.lvl / 2;

            std::cout << "You swing your sword...\n";
            std::cout << "You've delt " << player.playerDMG << " to the " << enemy.currentEnemy << std::endl;

            enemy.enemyHP -= player.playerDMG;
            Sleep(1000);
            CombatHUD();

            if (enemy.enemyHP >= 1) {
                std::cout << "\n";
                std::cout << enemy.currentEnemy << " counter attacks...\n";

                player.totalHP -= enemy.enemyDMG;

                std::cout << "The hit lands and you are delt <-> " << enemy.enemyDMG << " HP: " << player.totalHP << std::endl;

                if (player.totalHP <= 0) {
                    player.totalHP = 0;
                    system("cls");
                    std::cout << "You have fallen great traveler!\n";
                    std::cout << "Slain by " << enemy.currentEnemy << "\n";
                    std::cout << "End stats\n" << "Level: " << player.lvl << " Fallen: " << player.name << std::endl;
                    Sleep(3500);
                    exit(0);
                }
            }
            else if (enemy.enemyHP <= 0) {
                enemy.enemyHP = 0;
                std::cout << "\n";
                std::cout << enemy.currentEnemy << " has been slain!" << " You have earned " << enemy.enemyXP << " xp.\nGood Hunting\n";

                if (player.lvl != player.maxLVL) {
                    player.currentXP += enemy.enemyXP;
                    lvlUP();
                }
                Sleep(1200);
                HUD();
            }
            Sleep(1000);
            Combat();
        }
        //Block
        else if (playerATK == 2) {
            std::cout << "You guard against their strike...\n";
            int i = rand() % 100 + 1;

            if (i >= 50) {
                std::cout << "You succefully guarded!\n";
                player.heal = player.lvl * 10 / 2;
                std::cout << "You have been Healed for " << player.heal << std::endl;

                player.totalHP += player.heal;
                Sleep(1000);
                Combat();
            }
            else {
                std::cout << "The enemy broke through your guard!\n";
                player.totalHP -= enemy.enemyDMG;
                std::cout << "You were delt " << enemy.enemyDMG << " HP: " << player.totalHP << std::endl;
                Sleep(1000);
                Combat();
            }
        }
        //Run
        else if (playerATK == 3) {
            std::cout << "You asttempt to flee!\n";
            int i = rand() % 100 + 1;
            if (i >= 50) {
                std::cout << "You manage to escape!\n";
                HUD();
            }
            else {
                std::cout << "Your flee attempt failed!\n";
                std::cout << "In your hurry the enemy manages to land a blow!\n";

                player.totalHP -= enemy.enemyDMG + 10;

                std::cout << "You were delt " << enemy.enemyDMG + 10 << " HP: " << player.totalHP << std::endl;
                Sleep(1000);
                Combat();
            }
        }
        //Invalid
        else {
            std::cout << "Invalid Choice\n";
            Sleep(600);
            Combat();
        }
    }
}

void Story::Moving() {
    int choice;
    int temp = rand() % 100 + 1;

    std::cout << "\n\n";
    std::cout << "1. Move Forward\n";
    std::cout << "2. Move Backward\n";
    std::cout << "3. Rest\n";
    std::cout << "\n\n";

    std::cin >> choice;

    //Moving Forward
    if (choice == 1) {
        std::cout << "You proceed onwards...\n";

        enemy.enemyGenerate();
        enemy.enemyLVL = player.lvl;

        if (temp >= 40) {
            std::cout << "On your way you encounter a " << enemy.currentEnemy << "! \nYou draw your weapon to fight!\n";
            Sleep(1200);
            Combat();
        }

        std::cout << "The path is clear.\n";
        Sleep(600);
        HUD();
    }
    //Moving Backward
    else if (choice == 2) {
        std::cout << "You retrace some of your steps...\n";

        if (temp >= 50) {
            std::cout << "On your way you encounter a " << enemy.currentEnemy << "! You draw your weapon to fight!\n";
            Sleep(1000);
            Combat();
        }

        std::cout << "The path is clear.\n";
        Sleep(600);
        HUD();
    }
    //Resting
    else if (choice == 3) {
        if (temp >= 85) {
            std::cout << "You find yourslef ambusahed by a " << enemy.currentEnemy << "! You're staggered, but ready your weapon!\n";
            Sleep(1000);
            Combat();
        }

        std::cout << "You lay you belongings and take in the environment.\n";
        if (player.totalHP <= 99) {
            player.totalHP += 10 * player.lvl;
        }
        std::cout << "You recovered some health while resting. HP = " << player.totalHP << std::endl;
        Sleep(1000);
        HUD();
    }
    //Invalid Option
    else {
        std::cout << "Invalid Choice\n";
        Sleep(600);
        Moving();
    }
}

void Story::lvlUP() {
    if (player.currentXP >= player.xp_to_lvl) {
        player.xp_to_lvl += floor(player.lvl + 25 * pow(2, player.lvl / 2));
        player.totalHP = floor(player.totalHP + 13 * pow(2, player.lvl / 8));
        player.playerDMG = player.baseDMG * player.lvl / 2;

        if (player.lvl >= player.minLVL && player.lvl <= player.maxLVL) {
            player.lvl++;
        }
        else {
            player.lvl = 100;
        }
        player.maxHP = player.totalHP;
        std::cout << "You have leveled up!\n";
        std::cout << "You are now level " << player.lvl << std::endl;
        std::cout << "Your total health is: " << player.totalHP << std::endl;
        Sleep(1000);
        lvlUP();
    }

    Sleep(3000);
    HUD();
}
#include "Story.h"

Story story;

int main() {
    //Makes your character
    story.Start();

    //Starts the game
    story.HUD();
    story.Moving();

    system("pause");
}
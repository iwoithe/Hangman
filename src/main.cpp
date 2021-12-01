#include <iostream>

#include "game.hpp"

using namespace std;

int main()
{
    // Use a random seed
    srand(time(NULL));

    // Create an instance of the "Hangman::Game" class
    Hangman::Game game;
    // Display the title once
    game.display_title();
    // Initialise the game
    game.init();
    // Run the main loop
    game.main_loop();

    // Exit successfully
    return 0;
}

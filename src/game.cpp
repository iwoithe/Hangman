#include <iostream>
#include <fstream>

#include "game.hpp"

using namespace std;


bool Hangman::Game::check_letter(char letter)
{
    bool letter_changed = false;

    // Add the guessed lettor to the guessed lettors vector
    guessed_lettors.push_back(letter);

    for (int i = 0; i < word.size(); i++)
    {
        if (letter == word[i]) {
            // Set the letter in "guessed_word" at index "i" to be the letter in "word" at index "i"
            guessed_word[i] = word[i];
            letter_changed = true;
        }
    }

    if (letter_changed)
    {
        // At least one letter has been changed
        return true;
    }

    // Subtract a life
    lives_remaining -= 1;

    return false;
}


bool Hangman::Game::check_play_again()
{
    cout << endl;

    // Vectors containing the different "Play again" options
    // TODO: Use these vectors in the conditionals
    string yes_answers[4] = {"Y", "y", "Yes", "yes"};
    string no_answers[4] = {"N", "n", "No", "no"};

    string input;

    while (true)
    {
        // Get the user's answer
        cout << "Do you want to play again (Y[es] or N[o])? ";
        cin >> input;

        if ((input == "Y") || (input == "y") || (input == "Yes") || (input == "yes") || (input == "N") || (input == "n") || (input == "No") || (input == "no")) {
            // The input is correct
            break;
        }
    }

    if ((input == "Y") || (input == "y") || (input == "Yes") || (input == "yes")) {
        // The user wants to play again
        return true;
    } else {
        // The user does not want to play again
        return false;
    }
}


void Hangman::Game::display_title()
{
    // Show the title (and how to play)
    cout << endl << "H A N G M A N" << endl << endl;
    cout << "Free and open source (GNU General Public License v3)" << endl << endl;
    cout << "How to Play:" << endl;
    cout << "  Follow the prompts" << endl;
    cout << "  You can guess multiple letters at once" << endl;
    cout << "  Be careful! You only have 7 lives" << endl << endl;
}


bool Hangman::Game::get_playing()
{
    // Get the playing variable
    return playing;
}


void Hangman::Game::set_playing(bool p)
{
    // Set the playing variable
    playing = p;
}


bool Hangman::Game::check_lives_remaining()
{
    // Check the number of lives left
    return lives_remaining > 0;
}


int Hangman::Game::get_lives()
{
    // Gets the number of lives left
    return lives_remaining;
}


void Hangman::Game::set_lives(int lives)
{
    // Sets the number of lives left
    lives_remaining = lives;
}


char Hangman::Game::get_input()
{
    // Get the typed letter
    char input_letter;
    cout << endl << "Enter a letter: ";
    cin >> input_letter;
    cout << endl;

    // Return the letter
    return input_letter;
}


void Hangman::Game::init()
{
    // Reset the base variables (this is important when playing again)
    playing = true;
    lives_remaining = 7;
    guessed_lettors = {};
    guessed_word = {};

    // Set a new word
    set_word(get_random_word());
}


void Hangman::Game::main_loop()
{
    // The main loop
    while (get_playing())
    {
        // Update the display
        update_display();
        // Get the typed letter and check if it is in the word
        check_letter(get_input());

        if (is_word_guessed())
        {
            // The word has been found
            // Update the display
            update_display();
            // Display the "You won" message
            cout << "You won!" << endl << "You had " << get_lives() << " lives remaining" << endl;
            // Break the loop
            set_playing(false); 
        }

        if (!check_lives_remaining()) {
            // No lives are left
            // Display the "Game over" message
            cout << "Game over!" << endl << "The word was: " << get_word() << endl;
            // Break the loop
            set_playing(false);
        }
    }

    if (check_play_again()) {
        // User wants to play again
        // Reset the variables
        init();
        // Run the main loop again
        main_loop();
    }
}


string Hangman::Game::get_random_word()
{
    // Open the file with all the words in it
    ifstream words_file("words.txt");

    // Set a vector containing the words
    vector<string> words = {};

    for (string word; words_file >> word;)
    {
        // Add each word to the words vector
        words.push_back(word);
    }

    // Pick a random number
    int random_index = rand() % words.size();
    
    // Use the random number as an index to the words vector
    return words[random_index];
}


void Hangman::Game::update_display()
{
    cout << "---" << endl << endl;

    // TODO: There is a bug when the user enters a letter already entered
    //       A life *isn't* being subtracted, however the board updates and
    //       displays the next part of hangman
    cout << board[lives_remaining - 1] << endl;

    cout << endl;

    cout << "Guessed Word: ";

    for (int i = 0; i < guessed_word.size(); i++)
    {
        // Display the values from the guessed letters
        cout << guessed_word[i] << " ";
    }

    cout << endl << endl;

    cout << "Guessed Letters: ";

    for (int i = 0; i < guessed_lettors.size(); i++)
    {
        // Display the list of guessed letters
        cout << guessed_lettors[i] << " ";
    }

    cout << endl << endl;
}


string Hangman::Game::get_word()
{
    // Get the word
    return word;
}


void Hangman::Game::set_word(string w)
{
    // Set the word
    word = w;

    for (int i = 0; i < word.size(); i++)
    {
        // Add '_' for each character in the word as an unknown placeholder
        guessed_word.push_back('_');
    }
}


bool Hangman::Game::is_word_guessed()
{
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed_word[i] != word[i]){
            // Letter does not equal the same letter in the word
            // Word is not complete 
            return false;
        }
    }

    // The whole word has been guessed correctly
    return true;

}

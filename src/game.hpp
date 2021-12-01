#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

using namespace std;

namespace Hangman
{
    class Game;
} // namespace Hangman


class Hangman::Game
{

private:
    // TODO: Prefix all variables with "m_" (short for member)
    bool playing = true;
    int lives_remaining = 7;
    // Use a vector as elements need to be added to this variable
    vector<char> guessed_lettors;
    string word;
    // Use a vector as elements need to be added to this variable
    vector<char> guessed_word;

    // The board is stored in an array (not a vector) as no elements need to be added or removed
    string board[7] = {"  +===+\n  |   |\n  0   |\n /|\\  |\n / \\  |\n      |\n=======",
                       "  +===+\n  |   |\n  0   |\n /|\\  |\n /    |\n      |\n=======",
                       "  +===+\n  |   |\n  0   |\n /|\\  |\n      |\n      |\n=======",
                       "  +===+\n  |   |\n  0   |\n /|   |\n      |\n      |\n=======",
                       "  +===+\n  |   |\n  0   |\n  |   |\n      |\n      |\n=======",
                       "  +===+\n  |   |\n  0   |\n      |\n      |\n      |\n=======",
                       "  +===+\n  |   |\n      |\n      |\n      |\n      |\n======="};

public:
    bool check_letter(char letter);

    bool check_play_again();

    void display_title();

    // Methods for the "playing" variable
    bool get_playing();
    void set_playing(bool p);

    char get_input();

    // Methods for the "lives_remaining" variable
    bool check_lives_remaining();
    int get_lives();
    void set_lives(int lives);

    void init();

    void main_loop();

    string get_random_word();
    
    void update_display();

    // Methods for the "word" variable
    string get_word();
    void set_word(string w);

    bool is_word_guessed();
};

#endif // GAME_HPP

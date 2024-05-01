#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <vector>
#include <string>

// Pelilaudan alkioiden tyyppi.
// Type of the elements in the gameboard.
enum Element_type {ZERO, ONE, EMPTY};

// Vakiot pelilaudan koon määrittelemiseen.
// Constants for the size of the gameboard.
const int NUMBER_OF_SYMBOLS = 3;
const int SIZE = 2 * NUMBER_OF_SYMBOLS;

// Vakio todennäköisyysjakauman ylärajaa varten.
// Nollilla ja ykkösillä on sama todennäköisyys, vaikkapa x, ja tyhjien
// todennäköisyyden voidaan arvioida olevan 6x, jolloin jakaumassa
// on yhteensä kahdeksan pistettä (lukua), joten sopiva väli on esim. [0..7].
//
// Constant for the upper bound of probability distribution.
// Zeros and ones have the same probability, say x, and the estimated
// probability of empties is 6x, whereupon their sum is 8x, and thus,
// the interval must have eigth points, as [0..7].
const int DISTR_UPPER_BOUND = 7;

// Vasemmanpuoleisimman sarakkeen koko, tarvitaan pelilaudan tulostamisessa.
// Width of the left-most column, needed in printing the gameboard.
const unsigned int LEFT_COLUMN_WIDTH = 5;


class GameBoard
{
public:
    // Rakentaja.
    // Constructor.
    GameBoard();

    // Tulostaa pelilaudan.
    // Prints the gameboard.
    void print() const;

    // Method to fill the game board randomly using a given seed.
    void fill_random(unsigned int seed);

    // Method to fill the game board with user-provided input.
    bool fill_user_input(const std::string& input);

    // Method to check if the game is over (i.e., if the game board is filled according to the rules).
    bool is_game_over() const;

    // Method to check if a move (adding an element) is valid.
    bool is_valid_move(unsigned int x, unsigned int y, Element_type element) const;

    // Method to add an element to the game board.
    void add_element(unsigned int x, unsigned int y, Element_type element);

private:
    // Tulostaa annetun pituisen rivin annettua merkkiä.
    // Prints a line with the given length and the given character.
    void print_line(unsigned int length, char fill_character) const;

    // Ratkaisemattoman pelilaudan tuottavat siemenluvut väliltä [1..50].
    // Seed values, from [1..50], producing non-solvable gameboard.
    const std::vector<unsigned int> BAD_SEEDS = { 2, 8, 12, 13, 16, 20, 21, 23,
                                                  26, 29, 31, 32, 34, 41, 42,
                                                  43, 44, 46 };
    // Add a 2D vector to represent the game board
        std::vector<std::vector<Element_type>> board;
};

#endif // GAMEBOARD_HH

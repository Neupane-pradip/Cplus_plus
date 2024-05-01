// gameboard.cpp
#include "gameboard.hh"
#include <iostream>
#include <random>
#include <vector>

GameBoard::GameBoard()
{
    // Initialize the game board with EMPTY elements
    board = std::vector<std::vector<Element_type>>(SIZE, std::vector<Element_type>(SIZE, EMPTY));
}

void GameBoard::print() const
{
    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '=');

    std::cout << "|   | ";
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        std::cout << i + 1 << " ";
    }
    std::cout << "|" << std::endl;

    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '-');

    for(unsigned int i = 0; i < SIZE; ++i)
    {
        std::cout << "| " << i + 1 << " | ";
        for(unsigned int j = 0; j < SIZE; ++j)
        {
            // Print the game board element (i, j)
            switch (board[i][j])
            {
                case ZERO:
                    std::cout << "0 ";
                    break;
                case ONE:
                    std::cout << "1 ";
                    break;
                case EMPTY:
                    std::cout << "  ";
                    break;
            }
        }
        std::cout << "|" << std::endl;
    }

    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '=');
}

void GameBoard::print_line(unsigned int length, char fill_character) const
{
    for(unsigned int i = 0; i < length; ++i)
    {
        std::cout << fill_character;
    }
    std::cout << std::endl;
}
// Method to check if the game is over (i.e., if the game board is filled according to the rules)
bool GameBoard::is_game_over() const {
    // Implement the logic to check if the game is over
}

// Method to check if a move (adding an element) is valid
bool GameBoard::is_valid_move(unsigned int x, unsigned int y, Element_type element) const {
    // Implement the logic to check if the move is valid
}

// Method to add an element to the game board
void GameBoard::add_element(unsigned int x, unsigned int y, Element_type element) {
    // Implement the logic to add an element to the game board
}

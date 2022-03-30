#include "board.h"
#include <iostream>

const char Water = ' ';
const char Hit = 'X';
const char Miss = 'o';
const char Ship = 's';

/* Creates a new board object
    - sets x and y lengths
    - sets up empty game board
    - adds ships randomly to the board
*/
Board::Board()
{
    x = 8;
    y = 8;
    shipCount = maxShips;
    GameBoard = InitializeBoard();
}

Board::~Board()
{
    delete[] GameBoard;
}

// Creates board filled with empty water spaces then runs PlaceShips()
char **Board::InitializeBoard()
{
    GameBoard = new char *[y];
    for (int i = 0; i < x; i++)
    {
        GameBoard[i] = new char[x];
    }

    for (int c = 0; c < y; c++)
    {
        for (int r = 0; r < x; r++)
        {
            GameBoard[c][r] = Water;
        }
    }
    GameBoard = PlaceShips();
    return GameBoard;
}

// Fills board with ships
char **Board::PlaceShips()
{
    srand((unsigned)time(0));
    int shipsCreated = 0;
    while (shipsCreated < maxShips)
    {
        int row = (rand() % x), col = (rand() % y);

        if (GameBoard[row][col] != Ship)
        {
            GameBoard[row][col] = Ship;
            shipsCreated++;
        }
    }
    return GameBoard;
}

// Outputs the current state of the board
void Board::displayBoard()
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (j == 0)
            {
                std::cout << '|' << GameBoard[i][j] << '|';
            }
            else
            {
                std::cout << GameBoard[i][j] << '|';
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Ships Remaining: " << shipCount << std::endl;
    std::cout << "\n\n\n";
}
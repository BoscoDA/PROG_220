#include "board.h"
#include "game.h"
#include <iostream>
#include <string>
#include <vector>

const int BOARD_X = 8;
const int BOARD_Y = 8;

Board GameBoard;
Board ShadowBoard;

std::vector<std::pair<int, int>> guesses;
std::vector<std::pair<int, int>> adj;

// Game setup logic held inside
void Game::Setup()
{
    GameBoard.displayBoard();
}

// Gameloop logic held inside
void Game::Start()
{
    while (GameBoard.GetShipCount() > 0)
    {
        Fire();
        GameBoard.displayBoard();
    }
}

// Iterates through the shadow board diagonally for the next spot that is suspected to have a ship
void Game::Guess()
{
    int x = 0, y = 0, index = 0;
    int row = BOARD_X, col = BOARD_Y;

    while (index < (BOARD_X * BOARD_Y))
    {
        if (ShadowBoard.GetGameBoard()[y][x] != 'X')
        {
            guesses.insert(guesses.begin(), std::pair<int, int>(x, y));
            break;
        }
        else
        {
            int sum = y + x;
            bool isEven = sum % 2 == 0;
            if (isEven)
            {
                if (x < col - 1 && y > 0)
                {
                    x++;
                    y--;
                }
                else if (x < col - 1)
                {
                    x++;
                }
                else
                {
                    y++;
                }
            }
            else
            {
                if (y < row - 1 && x > 0)
                {
                    x--;
                    y++;
                }
                else if (y < row - 1)
                {
                    y++;
                }
                else
                {
                    x++;
                }
            }
        }
        index++;
    }
}

// Logic for firing on a spot
void Game::Fire()
{
    if (guesses.empty() == true)
    {
        Guess();
    }
    int x = guesses.begin()->first;
    int y = guesses.begin()->second;
    std::cout << "\nGuess:(" << x + 1 << "," << y + 1 << ") is a ";
    GetAdj(x, y);
    std::cout << EvaluatePoint(x, y) << std::endl;
    guesses.erase(guesses.begin());
    adj.clear();
}

// Finds all sqaures sharing a side with the guess that are within the bounds of the board
void Game::GetAdj(int x, int y)
{
    if (y - 1 >= 0)
    {
        adj.insert(adj.end(), std::pair<int, int>(x, y - 1));
    }
    if (x + 1 < 8)
    {
        adj.insert(adj.end(), std::pair<int, int>(x + 1, y));
    }
    if (y + 1 < 8)
    {
        adj.insert(adj.end(), std::pair<int, int>(x, y + 1));
    }
    if (x - 1 >= 0)
    {
        adj.insert(adj.end(), std::pair<int, int>(x - 1, y));
    }
}

// Checks adjacent spaces for ships.
// returns 1 if true
// returns 0 if false.
int Game::EvalAdj()
{
    for (auto it = adj.begin(); it != adj.end(); it++)
    {
        if ((GameBoard.GetGameBoard()[it->second][it->first] == 's') & (ShadowBoard.GetGameBoard()[it->second][it->first] != 'X'))
        {
            return 1;
        }
    }
    return 0;
}

// Checks if the guess was either a HIT, NEAR MISS, or a MISS
std::string Game::EvaluatePoint(int x, int y)
{
    if (GameBoard.GetGameBoard()[y][x] == 's')
    {
        return Hit(x, y);
    }
    else if (EvalAdj() == 1)
    {
        return NearMiss(x, y);
    }
    else
    {
        return Miss(x, y);
    }
}

// Logic for when a guess is a HIT
std::string Game::Hit(int x, int y)
{
    GameBoard.GetGameBoard()[y][x] = 'X';
    ShadowBoard.GetGameBoard()[y][x] = 'X';
    GameBoard.DecreaseShipCount();
    return "Hit";
}

// Logic for when a guess is a NEAR MISS
std::string Game::NearMiss(int x, int y)
{
    GameBoard.GetGameBoard()[y][x] = 'X';
    ShadowBoard.GetGameBoard()[y][x] = 'X';
    guesses = adj;
    return "NEAR MISS";
}

// Logic for when a guess is a MISS
std::string Game::Miss(int x, int y)
{
    GameBoard.GetGameBoard()[y][x] = 'X';
    ShadowBoard.GetGameBoard()[y][x] = 'X';
    for (auto it = adj.begin(); it != adj.end(); it++)
    {
        ShadowBoard.GetGameBoard()[it->second][it->first] = 'X';
    }
    return "MISS";
}
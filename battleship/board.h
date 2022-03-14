#pragma once

class Board
{
public:
    Board(int x_length, int y_length);
    ~Board();
    int GetLengthX() { return x; }
    int GetLengthY() { return y; }
    int GetmaxShips() { return maxShips; }
    int GetShipCount() { return shipCount; }
    int DecreaseShipCount() { return shipCount--; }
    char **GetGameBoard() { return GameBoard; }
    char **InitializeBoard();
    char **PlaceShips();
    void displayBoard();

private:
    int x;
    int y;
    char **GameBoard;
    int shipCount;
    const int maxShips = 5;
};
#include <iostream>
#include <string>
#include <cstdlib>
#include "game.h"

/* ++++++++++++Project Instructions++++++++++++++

1) You are provided 1 main.cpp file and a Makefile, you are not required to use these they are just there for your convenience
(if you are on a mac feel free to use xcode or visual studio on windows)

1) To use the makefile where it has the OBJ variable put any .cpp files you have there that arent main.cpp
 but replace the .cpp file extension with the .o file extension

the following is if you have board.cpp and types.cpp. Note you dont have to have these files, they are just an example
EXAMPLE: OBJ = board.o types.o

2) put all of your header files in the DEPS
EXAMPLE: DEPS = board.h types.h

3) to compile your app just run `make` in your oode directory and it should run and, afterwards there will be a file called app in your directory.

4) run app with ./app


++++++++++++Game Rules++++++++++++++
You must create a board that is 8x8 spaces. each space can hold one ship. ships dimmensions are 1x1
(yes, i know its more like minesweeper but i already called it battleship)

You must randomly place the ships throughout the board and have a computer guess where they are in some organized fashion.
This means you have to write an AI to most efficiently search for ships that you can think of.

When you make a guess for coordinates (x, y) it can return one of three values: HIT, MISS, NEAR MISS.
        HIT: you guessed the right square.
        MISS: there is not a ship adjacent in any direction to your guess.
        NEAR MISS: there is a square adjacent in a direction to your guess.

You must use these return statuses in your algorithm.
 */

int main()
{
  Game game;
  game.Setup();
  game.Start();
}

#pragma once
#include <iostream>
#include "deck.h"
#include "player.h"

class Game
{
public:
    Game();
    Game(const Game &)
    {
        // std::cout << "Copied Game" << std::endl;
    }
    ~Game()
    {
        delete CurrentDeck;
    }
    void Setup();
    void GameLoop();
    void PlayerTurn();
    void BotTurn();
    void End();

private:
    Player CurrentPlayer = Player("NULL");
    Player Bot = Player("NULL");
    Deck *CurrentDeck;
    int EndGame;
};
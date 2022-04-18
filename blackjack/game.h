#pragma once
#include <iostream>
#include "deck.h"
#include "player.h"

class Game
{
public:
    Game();
    void GameSetup();
    void GameLoop();
    void PlayerTurn();
    void BotTurn();

private:
    Player CurrentPlayer = Player("NULL");
    Player Bot = Player("NULL");
    Deck CurrentDeck;
};
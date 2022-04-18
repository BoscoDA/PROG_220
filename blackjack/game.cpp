#include "game.h"
Game::Game()
{
    CurrentPlayer = Player("Nick");
    Bot = Player("Bot");
    CurrentDeck = Deck();
    CurrentDeck.ShuffleDeck();
}

void Game::GameLoop()
{
    PlayerTurn();
}

void Game::PlayerTurn()
{
    CurrentPlayer.SetHand(CurrentDeck.DealCard());
    CurrentPlayer.SetHand(CurrentDeck.DealCard());
    CurrentPlayer.DisplayHand();
    std::cout << "Total:" << CurrentPlayer.GetHandTotal() << std::endl;
}
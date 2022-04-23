#include "game.h"
Game::Game()
{
    CurrentPlayer = Player("Nick");
    Bot = Player("Bot");
    CurrentDeck = new Deck();
    CurrentDeck->ShuffleDeck();
    EndGame = 0;
}

void Game::GameLoop()
{
    int count = 0;
    while (count < 100)
    {
        Setup();
        PlayerTurn();
        BotTurn();
        End();
        count++;
    }
}

void Game::Setup()
{
    CurrentPlayer.SetHand(CurrentDeck->DealCard());
    CurrentPlayer.SetHand(CurrentDeck->DealCard());

    Bot.SetHand(CurrentDeck->DealCard());
    Bot.SetHand(CurrentDeck->DealCard());
}

void Game::PlayerTurn()
{
    do
    {
        CurrentPlayer.DisplayHand();
        std::cout << CurrentPlayer.GetName() << " Total:" << CurrentPlayer.GetHandTotal() << std::endl;
        std::cout << "What would you like to do?\n  1) Hit\n  2) Stand" << std::endl;

        int input;
        std::cin >> input;
        if (input == 1)
        {
            CurrentPlayer.SetHand(CurrentDeck->DealCard());
        }
        else if (input == 2)
        {
            EndGame = true;
        }
        else
        {
            std::cout << "Not a valid input." << std::endl;
        }
    } while ((CurrentPlayer.GetHandTotal() <= 21) & (EndGame == 0));
}

void Game::BotTurn()
{
    if (Bot.GetHandTotal() < 17)
    {
        do
        {
            Bot.SetHand(CurrentDeck->DealCard());
        } while ((Bot.GetHandTotal() < 17) & (Bot.GetHandTotal() < 22));
    }
}

void Game::End()
{
    std::cout << "You had " << CurrentPlayer.GetHandTotal() << ", the dealer had " << Bot.GetHandTotal() << std::endl;
    if ((CurrentPlayer.GetHandTotal() <= 21) & (Bot.GetHandTotal() <= 21))
    {
        if (CurrentPlayer.GetHandTotal() > Bot.GetHandTotal())
        {
            std::cout << "\nYou win this round!";
        }
        else if (CurrentPlayer.GetHandTotal() == Bot.GetHandTotal())
        {
            std::cout << "\nYou tied with the dealer!";
        }
        else
        {
            std::cout << "\nYou lose this round!";
        }
    }
    else if (CurrentPlayer.GetHandTotal() > 21)
    {
        std::cout << "\nYou bust, you lose this round!";
    }

    else if (Bot.GetHandTotal() > 21)
    {
        std::cout << "\nDealer busts, you win this round!";
    }
    CurrentPlayer.GetHand().clear();
    Bot.GetHand().clear();
}
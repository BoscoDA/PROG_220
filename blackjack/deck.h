#pragma once
#include "card.h"
#include <vector>
#include "player.h"

class Deck
{
public:
    Deck();
    Deck(const Deck &)
    {
        // std::cout << "Copied" << std::endl;
    }
    ~Deck()
    {
        for (auto d : deck)
        {
            // std::cout << "Deleted" << std::endl;
            delete d;
        }
    }
    void ShuffleDeck();
    std::vector<Card *> GetDeck() { return this->deck; }
    void DisplayDeck();
    Card *DealCard();

private:
    std::vector<Card *> deck;
};
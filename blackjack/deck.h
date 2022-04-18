#pragma once
#include "card.h"
#include <vector>
#include "player.h"

class Deck
{
public:
    Deck();

    void ShuffleDeck();
    std::vector<Card> GetDeck() { return this->deck; }
    void DisplayDeck();
    Card DealCard();

private:
    std::vector<Card> deck;
};
#include "card.h"
#include <iostream>
Card::Card(std::string suit, std::string rank, int value)
{
    Suit = suit;
    Rank = rank;
    NumValue = value;
}

void Card::DisplayCard()
{
    std::cout << Rank << " of " << Suit << std::endl;
}
#pragma once
#include <vector>
#include "card.h"
#include <string>

class Player
{
public:
    Player(std::string name);
    std::vector<Card> GetHand() { return this->Hand; }
    void SetHand(Card card);
    int GetHandTotal();
    void DisplayHand();

private:
    std::vector<Card> Hand;
    int HandTotal;
    std::string Name;
};
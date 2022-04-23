#pragma once
#include <vector>
#include "card.h"
#include <string>

class Player
{
public:
    Player(std::string name);
    Player(const Player &)
    {
        // std::cout << "Copied Player" << std::endl;
    }
    ~Player()
    {
        for (auto d : Hand)
        {
            // std::cout << "Deleted Player" << std::endl;
            delete d;
        }
    }
    std::vector<Card *> GetHand() { return this->Hand; }
    void SetHand(Card *card);
    int GetHandTotal();
    void DisplayHand();
    inline std::string GetName() { return Name; }

private:
    std::vector<Card *> Hand;
    int HandTotal;
    std::string Name;
};
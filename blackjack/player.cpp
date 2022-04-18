#include "player.h"

Player::Player(std::string name)
{
    Name = name;
}

int Player::GetHandTotal()
{
    int total = 0;
    for (auto it = Hand.begin(); it != Hand.end(); it++)
    {
        total += it->GetNumValue();
    }
    return total;
}

void Player::DisplayHand()
{
    for (auto it = Hand.begin(); it != Hand.end(); it++)
    {
        Card temp = *it;
        temp.DisplayCard();
    }
}
void Player::SetHand(Card card)
{
    this->Hand.push_back(card);
}

#include "deck.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
std::string Rank[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
std::string Suit[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
int NumVal[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
Deck::Deck()
{
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Card temp = Card(Suit[j], Rank[i], NumVal[i]);
            deck.push_back(temp);
        }
    }
}

void Deck::DisplayDeck()
{
    for (auto it = deck.begin(); it != deck.end(); it++)
    {
        Card temp = *it;
        temp.DisplayCard();
    }
}

void Deck::ShuffleDeck()
{
    std::random_shuffle(deck.begin(), deck.end());

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

Card Deck::DealCard()
{
    Card temp = *deck.rbegin();
    deck.pop_back();
    return temp;
}

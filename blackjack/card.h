#pragma once
#include <string>
class Card
{
public:
    Card(std::string suit, std::string rank, int value);
    std::string GetSuit() { return Suit; }
    std::string GetRank() { return Rank; }
    int GetNumValue() { return NumValue; }
    void SetNumValue(int val) { NumValue = val; }
    void DisplayCard();

private:
    std::string Suit;
    std::string Rank;
    int NumValue;
};
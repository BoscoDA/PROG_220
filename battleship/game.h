#pragma once
#include <string>
#include <vector>
#include <map>

class Game
{
public:
    void Setup();
    void Start();

private:
    void Fire();
    void GetAdj(int x, int y);
    int EvalAdj();
    std::string EvaluatePoint(int x, int y);
    std::string Hit(int x, int y);
    std::string NearMiss(int x, int y);
    std::string Miss(int x, int y);
    void Guess();
};

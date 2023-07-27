#pragma once
#include "Score.h"


struct leaderBoard
{
    vector<Score> scores;
    leaderBoard();
    void Print();
    void addNewScore(Score s, int n);
    void changeScore(Score s);
};
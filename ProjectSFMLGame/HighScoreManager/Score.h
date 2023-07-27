#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MAX_WIDTH_NAME 251
using namespace std;

struct Score
{
    int score;
    char name[MAX_WIDTH_NAME];
    Score();
    Score(int score, char name[MAX_WIDTH_NAME]);
    void Print();
    bool operator== (const Score& score);
};

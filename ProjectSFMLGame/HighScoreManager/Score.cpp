#include "Score.h"

Score::Score() {
    score = 0;
}

Score::Score(int score, char name[MAX_WIDTH_NAME]) {
    this->score = score;
    memcpy(this->name, name, MAX_WIDTH_NAME); // Copia una porcion de memoria de un origen a un destino
}

void Score::Print() {
    cout << "Name:" << name << " - " << "Score:" << score << endl;
}

bool Score::operator==(const Score& score)
{
    string s1 = name;
    string s2 = score.name;
    return s1 == s2;
}


#include "LeaderBoard.h"
#include <algorithm>

leaderBoard::leaderBoard() {
	vector<Score> scores;
}


void leaderBoard::Print() {
	for (int i = 0; i < scores.size(); i++) {
		Score s = scores[i];
		s.Print();
	}
}

bool ScoreCompare(const Score& a, const Score& b) {
	return a.score > b.score;
}


void leaderBoard::addNewScore(Score s, int n)
{
	scores.push_back(s);
	sort(scores.begin(), scores.end(), ScoreCompare);
	if (scores.size() > n) {
		scores.pop_back();
	}
}

//modifica un score (la igualdad entre scores la defini comparando names) y lo coloca en su respectiva posicion en la lista.
void leaderBoard::changeScore(Score s) {
	scores.erase(find(scores.begin(), scores.end(), s));
	this->addNewScore(s, scores.size() + 1);
}

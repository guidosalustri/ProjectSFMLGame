#include "LeaderBoard.h"

void writeScoresInFile(leaderBoard leaderBoard, string filename) {
	fstream bfile;
	bfile.open(filename, ios::out | ios::binary);
	if (bfile.is_open()) {
		for (int i = 0; i < leaderBoard.scores.size(); i++) {
			bfile.write((char*)&leaderBoard.scores[i], sizeof(Score));
		}
		bfile.close();
	}
}

leaderBoard fileToVectorScores(string filename) {
	fstream bfile;
	bfile.open(filename, ios::in | ios::binary);
	leaderBoard lb;
	Score readScore;
	if (bfile.is_open()) {
		while (!bfile.eof()) {
			bfile.read((char*)&readScore, sizeof(Score));
			lb.scores.push_back(readScore);
		}
		bfile.close();
		lb.scores = vector<Score>(lb.scores.begin(), lb.scores.end() - 1);
		return lb;
	}
	else { return lb; }
}
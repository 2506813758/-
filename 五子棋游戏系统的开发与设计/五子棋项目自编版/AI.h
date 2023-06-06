#pragma once

#include"Board.h"

#include<vector>
#include<time.h>

using namespace std;

class AI
{
public:
	void init(Board* board);
	void go();
	void think();

private:
	Board* board;

	int score_map[15][15];
};


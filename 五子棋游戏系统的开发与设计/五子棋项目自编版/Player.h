#pragma once

#include"Board.h"

class Player
{
public:
	void init(Board* board);
	void go();
private:
	Board* board;
};


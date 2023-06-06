#pragma once

#include"Player.h"
#include"AI.h"

#include<stdio.h>

class Game
{
public:
	Game(Player* player, AI* ai, Board* board);
	// ��Ϸ����
	void game(int num);

private:
	Player* player;
	AI* ai;
	Board* board;

	// ����Ӯ
	IMAGE image_b_win;
	// ����Ӯ
	IMAGE image_w_win;
};


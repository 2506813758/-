#pragma once

#include"Player.h"
#include"AI.h"

#include<stdio.h>

class Game
{
public:
	Game(Player* player, AI* ai, Board* board);
	// 游戏主体
	void game(int num);

private:
	Player* player;
	AI* ai;
	Board* board;

	// 黑子赢
	IMAGE image_b_win;
	// 白子赢
	IMAGE image_w_win;
};


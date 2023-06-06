#include "Game.h"

Game::Game(Player* player, AI* ai, Board* board)
{
	this->player = player;
	this->ai = ai;
	this->board = board;

	loadimage(&image_b_win, "data/win_black.jpg");
	loadimage(&image_w_win, "data/win_white.jpg");

	player->init(board);
	ai->init(board);
}

void Game::game(int num)
{
	board->init();
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, "΢���ź�");
	settextcolor(BLACK);
	while (1) {
		// ����
		{
			player->go();
			if (board->is_end()) {
				outtextxy(0, 48, "����Ӯ��");
				break;
			}
		}
		// ����
		{
			if (num == 2) {
				player->go();
			}
			else if (num == 1) {
					ai->go();
			}
			if (board->is_end()) {
				outtextxy(0, 48, "����Ӯ��");
				break;
			}
		}
	}
}


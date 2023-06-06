#include "Player.h"

void Player::init(Board* board)
{
	this->board = board;
}

void Player::go()
{
	// 鼠标信息
	MOUSEMSG msg;

	// 判断点击
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && board->click(msg.x, msg.y)) {
			break;
		}
	}

	board->down();
}

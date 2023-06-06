#include "Player.h"

void Player::init(Board* board)
{
	this->board = board;
}

void Player::go()
{
	// �����Ϣ
	MOUSEMSG msg;

	// �жϵ��
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && board->click(msg.x, msg.y)) {
			break;
		}
	}

	board->down();
}

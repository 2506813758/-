#include"Game.h"

#include<stdio.h>
#include<stdlib.h>

int main() {
	Player player;
	AI ai;
	Board board;
	Game game(&player, &ai, &board);

	char decdion;

start:
	system("cls");
	decdion = 0;
	printf("������\n");
	printf("1.������Ϸ\n");
	printf("3.˫�˶Ծ�\n");
	printf("4.�˳�\n");
	scanf_s("%c", &decdion);
	switch (decdion) {
	case '1':
		game.game(1);
		break;
	case '2':
		game.game(2);
		break;
	case '3':
		printf("��Ϸ���˳�\n");
		exit(1);
	default:
		goto start;
	}

	MOUSEMSG msg;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			closegraph();
			printf("��Ϸ�������������������\n");
			_getch();
			goto start;
		}
	}
}

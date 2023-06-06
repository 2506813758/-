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
	printf("五子棋\n");
	printf("1.单人游戏\n");
	printf("3.双人对决\n");
	printf("4.退出\n");
	scanf_s("%c", &decdion);
	switch (decdion) {
	case '1':
		game.game(1);
		break;
	case '2':
		game.game(2);
		break;
	case '3':
		printf("游戏已退出\n");
		exit(1);
	default:
		goto start;
	}

	MOUSEMSG msg;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			closegraph();
			printf("游戏结束，输入任意键返回\n");
			_getch();
			goto start;
		}
	}
}

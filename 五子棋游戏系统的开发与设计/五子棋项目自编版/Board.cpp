#include "Board.h"
#include<stdio.h>
void Board::init()
{
	// 黑子先手
	is_black = true;

	for (int row = 0; row < 15; row++) {
		for (int col = 0; col < 15; col++) {
			map[row][col] = 0;
		}
	}

	// 创建窗口
	initgraph(board_width, board_height);

	// 加载图片
	loadimage(&image_background, "data/board.jpg");
	loadimage(&image_chess_black[0], "data/black_1.jpg", chess_size, chess_size);
	loadimage(&image_chess_black[1], "data/black_2.jpg", chess_size, chess_size);
	loadimage(&image_chess_white[0], "data/white_1.jpg", chess_size, chess_size);
	loadimage(&image_chess_white[1], "data/white_2.jpg", chess_size, chess_size);

	// 绘制棋盘
	putimage(0, 0, &image_background);
	mciSendString("play data/music.mp3", 0, 0, 0);
}

bool Board::click(int x, int y)
{
	// 找到格子左顶点坐标
	int row = (y - margin_y) / chess_size;
	int col = (x - margin_x) / chess_size;
	int left_top_x = margin_x + col * chess_size;
	int left_top_y = margin_y + row * chess_size;

	// 设置点击距离上限
	int off_set = chess_size * 0.3;

	// 返回值
	int ret = false;

	// 点到格子左上角顶点的距离
	int len;

	while (1) {
		if (row < 0 || row >= 15 || col < 0 || col >= 15) break;
		// 当点在格子左上角时
		len = sqrt((x - left_top_x) * (x - left_top_x) + (y - left_top_y) * (y - left_top_y));
		if (len <= off_set) {
			pos.row = row;
			pos.col = col;
			if (map[pos.row][pos.col] == 0) {
				ret = true;
				break;
			}
		}

		// 当点在格子右上角时
		len = sqrt((left_top_x + chess_size - x) * (left_top_x + chess_size - x) + (y - left_top_y) * (y - left_top_y));
		if (len <= off_set) {
			pos.row = row;
			pos.col = col + 1;
			if (map[pos.row][pos.col] == 0) {
				ret = true;
				break;
			}
		}

		// 点在格子右下角时
		len = sqrt((left_top_x + chess_size - x) * (left_top_x + chess_size - x) + (left_top_y + chess_size - y) * (left_top_y + chess_size - y));
		if (len <= off_set) {
			pos.row = row + 1;
			pos.col = col + 1;
			if (map[pos.row][pos.col] == 0) {
				ret = true;
				break;
			}
		}

		// 点在格子左下角时
		len = sqrt((x - left_top_x) * (x - left_top_x) + (left_top_y + chess_size - y) * (left_top_y + chess_size - y));
		if (len <= off_set) {
			pos.row = row + 1;
			pos.col = col;
			if (map[pos.row][pos.col] == 0) {
				ret = true;
				break;
			}
		}

		break;
	}
	
	return ret;
}

void Board::down()
{
	// 计算落子位置
	int x = margin_x + pos.col * chess_size - chess_size / 2;
	int y = margin_y + pos.row * chess_size - chess_size / 2;
	// 落子
	if (is_black) {
		map[pos.row][pos.col] = chess_black;
		putimage(x, y, &image_chess_black[1], NOTSRCERASE);
		putimage(x, y, &image_chess_black[0], SRCERASE);
		is_black = !is_black;
	}
	else {
		map[pos.row][pos.col] = chess_white;
		putimage(x, y, &image_chess_white[1], NOTSRCERASE);
		putimage(x, y, &image_chess_white[0], SRCERASE);
		is_black = !is_black;
	}

}

int Board::get_data(int row, int col)
{
	return map[row][col];
}

void Board::modify_pos(Pos pos)
{
	this->pos = pos;
}

bool Board::is_end()
{
	setlinecolor(RED);

	int x1, x2;
	int y1, y2;
	int row = pos.row;
	int col = pos.col;

	int n;

	 // 检查输赢
	for (int i = 0; i < 5; i++) {
		// 检查横着的情况
		n = 4;
		if (col - i >= 0 && col - i + 4 < 15) {
			for (int j = 1; j <= 4; j++) {
				if (map[row][col - i] == map[row][col - i + j]) {
					n--;
				}
			}
		}
		if (n == 0) {
			win_line(row, col - i, row, col - i + 4);
			return true;
		}

		// 检查竖着的情况
		n = 4;
		if (row - i >= 0 && row - i + 4 < 15) {
			for (int j = 1; j <= 4; j++) {
				if (map[row - i][col] == map[row - i + j][col]) {
					n--;
				}
			}
		}
		if (n == 0) {
			win_line(row - i, col, row - i + 4, col);
			return true;
		}

		// 检查东北方方向
		n = 4;
		if (row - i >= 0 && row - i + 4 < 15 && col - i >= 0 && col - i + 4 < 15) {
			for (int j = 1; j <= 4; j++) {
				if (map[row - i][col - i] == map[row - i + j][col - i + j]) {
					n--;
				}
			}
		}
		if (n == 0) {
			win_line(row - i, col - i, row - i + 4, col - i + 4);
			return true;
		}

		// 检查西北方方向
		n = 4;
		if (row + i >= 0 && row + i - 4 < 15 && col - i >= 0 && col - i + 4 < 15) {
			for (int j = 1; j <= 4; j++) {
				if (map[row + i][col - i] == map[row + i - j][col - i + j]) {
					n--;
				}
			}
		}
		if (n == 0) {
			win_line(row + i, col - i, row + i - 4, col - i + 4);
			return true;
		}
	}
	
	return false;
}

void Board::win_line(int row1, int col1, int row2, int col2)
{
	int x1 = margin_x + col1 * chess_size - chess_size / 2 + chess_size / 2;
	int y1 = margin_y + row1 * chess_size - chess_size / 2 + chess_size / 2;
	int x2 = margin_x + col2 * chess_size - chess_size / 2 + chess_size / 2;
	int y2 = margin_y + row2 * chess_size - chess_size / 2 + chess_size / 2;
	line(x1, y1, x2, y2);
}



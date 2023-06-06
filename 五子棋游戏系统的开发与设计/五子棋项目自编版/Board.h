#pragma once

#include<graphics.h>
#include<math.h>
#include<conio.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment (lib, "winmm.lib")

// 棋子位置
struct Pos {
	int row;
	int col;
};

// 棋子种类
enum {
	chess_black = 1,
	chess_white = -1
};

class Board
{
public:
	// 初始化
	void init();
	// 点击
	bool click(int x, int y);
	// 落子
	void down();
	// 获取棋盘数据
	int get_data(int row, int col);
	// 修改落子位置
	void modify_pos(Pos pos);
	// 判断是否结束
	bool is_end();
	// 结束后将赢的子划线
	void win_line(int row1, int col1, int row2, int col2);

private:
	// 背景图片
	IMAGE image_background;
	// 黑子图片
	IMAGE image_chess_black[2];
	// 白子图片
	IMAGE image_chess_white[2];
	// 棋盘宽度
	int board_width = 746;
	// 棋盘高度
	int board_height = 500;
	// 左上角边界的x坐标
    int margin_x = 159;
	// 左上角边界的y坐标
	int margin_y = 48;
	// 棋子大小
	int chess_size = 31;
	// 地图信息
	int map[15][15];
	// 落子位置
	Pos pos;
	// 是否轮到黑子
	bool is_black;
};


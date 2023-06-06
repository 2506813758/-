#pragma once

#include<graphics.h>
#include<math.h>
#include<conio.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment (lib, "winmm.lib")

// ����λ��
struct Pos {
	int row;
	int col;
};

// ��������
enum {
	chess_black = 1,
	chess_white = -1
};

class Board
{
public:
	// ��ʼ��
	void init();
	// ���
	bool click(int x, int y);
	// ����
	void down();
	// ��ȡ��������
	int get_data(int row, int col);
	// �޸�����λ��
	void modify_pos(Pos pos);
	// �ж��Ƿ����
	bool is_end();
	// ������Ӯ���ӻ���
	void win_line(int row1, int col1, int row2, int col2);

private:
	// ����ͼƬ
	IMAGE image_background;
	// ����ͼƬ
	IMAGE image_chess_black[2];
	// ����ͼƬ
	IMAGE image_chess_white[2];
	// ���̿��
	int board_width = 746;
	// ���̸߶�
	int board_height = 500;
	// ���ϽǱ߽��x����
    int margin_x = 159;
	// ���ϽǱ߽��y����
	int margin_y = 48;
	// ���Ӵ�С
	int chess_size = 31;
	// ��ͼ��Ϣ
	int map[15][15];
	// ����λ��
	Pos pos;
	// �Ƿ��ֵ�����
	bool is_black;
};


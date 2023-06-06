#include "AI.h"

void AI::init(Board* board)
{
	this->board = board;

	srand(time(NULL));
}

void AI::go()
{
	think();
	Sleep(1000);
	board->down();
}

void AI::think()
{
	for (int row = 0; row < 15; row++) {
		for (int col = 0; col < 15; col++) {
			score_map[row][col] = 0;
		}
	}

	int black_num, white_num, empty_num;
	// 遍历棋盘
	for (int row = 0; row < 15; row++) {
		for (int col = 0; col < 15; col++) {
			if (board->get_data(row, col) != 0) continue;
			for (int y = -1; y <= 1; y++) {
				for (int x = -1; x <= 1; x++) {
					if (y == 0 && x == 0) continue;
					black_num = 0;
					empty_num = 0;
					for (int i = 1; i <= 4; i++) {
						int current_row = row + i * y;
						int current_col = col + i * x;
						if (current_row >= 0 && current_row < 15 && current_col >= 0 && current_col < 15) {
							if (board->get_data(current_row, current_col) == 1) {
								black_num++;
							}
							else if (board->get_data(current_row, current_col) == 0) {
								empty_num++;
								break;
							}
							else {
								break;
							}
						}
					}
					if (black_num == 1) {
						score_map[row][col] += 10;
					}
					else if (black_num == 2) {
						if (empty_num == 1) {
							score_map[row][col] += 30;
						}
						else if (empty_num == 2) {
							score_map[row][col] += 40;
						}
					}
					else if (black_num == 3) {
						if (empty_num == 1) {
							score_map[row][col] += 60;
						}
						if (empty_num == 2) {
							score_map[row][col] += 200;
						}
					}
					else if (black_num == 4) {
						score_map[row][col] += 20000;
					}
					for (int i = 1; i <= 4; i++) {
						int current_row = row - i * y;
						int current_col = col - i * x;
						if (current_row >= 0 && current_row < 15 && current_col >= 0 && current_col < 15) {
							if (board->get_data(current_row, current_col) == 1) {
								black_num++;
							}
							else if (board->get_data(current_row, current_col) == 0) {
								empty_num++;
								break;
							}
							else {
								break;
							}
						}
					}
					if (black_num == 1) {
						score_map[row][col] += 10;
					}
					else if (black_num == 2) {
						if (empty_num == 1) {
							score_map[row][col] += 30;
						}
						else if (empty_num == 2) {
							score_map[row][col] += 40;
						}
					}
					else if (black_num == 3) {
						if (empty_num == 1) {
							score_map[row][col] += 60;
						}
						if (empty_num == 2) {
							score_map[row][col] += 200;
						}
					}
					else if (black_num == 4) {
						score_map[row][col] += 20000;
					}

					empty_num = 0;
					white_num = 0;
					for (int i = 1; i <= 4; i++) {
						int current_row = row + i * y;
						int current_col = col + i * x;
						if (current_row >= 0 && current_row < 15 && current_col >= 0 && current_col < 15) {
							if (board->get_data(current_row, current_col) == -1) {
								white_num++;
							}
							else if (board->get_data(current_row, current_col) == 0) {
								empty_num++;
								break;
							}
							else {
								break;
							}
						}
					}
					if (white_num == 0) {
						score_map[row][col] += 5;
					}
					else if (white_num == 1) {
						score_map[row][col] += 10;
					}
					else if (white_num == 2) {
						if (empty_num == 1) {
							score_map[row][col] += 25;
						}
						else if (empty_num == 2) {
							score_map[row][col] += 50;
						}
					}
					else if (white_num == 3) {
						if (empty_num == 1) {
							score_map[row][col] += 55;
						}
						else if (empty_num == 2) {
							score_map[row][col] += 10000;
						}
					}
					else if (white_num == 4) {
						score_map[row][col] += 30000;
					}
					for (int i = 1; i <= 4; i++) {
						if (i == 0) continue;
						int current_row = row - i * y;
						int current_col = col - i * x;
						if (current_row >= 0 && current_row < 15 && current_col >= 0 && current_col < 15) {
							if (board->get_data(current_row, current_col) == -1) {
								white_num++;
							}
							else if (board->get_data(current_row, current_col) == 0) {
								empty_num++;
								break;
							}
							else {
								break;
							}
						}
					}
					if (white_num == 0) {
						score_map[row][col] += 5;
					}
					else if (white_num == 1) {
						score_map[row][col] += 10;
					}
					else if (white_num == 2) {
						if (empty_num == 1) {
							score_map[row][col] += 25;
						}
						else if (empty_num == 2) {
							score_map[row][col] += 50;
						}
					}
					else if (white_num == 3) {
						if (empty_num == 1) {
							score_map[row][col] += 55;
						}
						else if (empty_num == 2) {
							score_map[row][col] += 10000;
						}
					}
					else if (white_num == 4) {
						score_map[row][col] += 30000;
					}
				}
			}
		}
	}

	

	// 找出评分最高的点
	int max = 0;
	vector<Pos> max_points;
	Pos pos;
	for (int row = 0; row < 15; row++) {
		for (int col = 0; col < 15; col++) {
			if (score_map[row][col] > max) {
				max_points.clear();
				max = score_map[row][col];
				pos.row = row;
				pos.col = col;
				max_points.push_back(pos);
			}
			else if (score_map[row][col] == max) {
				pos.row = row;
				pos.col = col;
				max_points.push_back(pos);
			}
		}
	}
	int index = rand() % max_points.size();
	board->modify_pos(max_points[index]);
}

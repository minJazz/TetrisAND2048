#pragma once


#define WIDE 13
#define HIGHT 21

#define WALL 0
#define EMPTY 1
#define ACTIVE_BLOCK 2
#define INACTIVE_BLOCK 3

int map[HIGHT][WIDE]; //바뀐
int map_c[HIGHT][WIDE]; //이전

int total_e_line = 0;
void gotoxy(int x, int y);

int init_map() {	//맵 초기값 설정

	total_e_line = 0;
	for (int w = 0; w < WIDE; w = w + 1) {
		map[0][w] = 1;
	}

	for (int h = 1; h < HIGHT - 1; h = h + 1) {
		for (int w = 0; w < WIDE; w = w + 1) {
			switch (w) {
			case 0:
			case WIDE - 1:
				map[h][w] = 0;
				break;

			default:
				map[h][w] = 1;
			}
		}
	}

	for (int w = 0; w < WIDE; w = w + 1) {
		map[HIGHT - 1][w] = 0;
	}

	return 0;
}

int map2view() {	//테트리스맵 출력하는 함수
	printf("\n\n");
	for (int h = 0; h < HIGHT; h = h + 1) {
		printf("    ");
		for (int w = 0; w < WIDE; w = w + 1) {
			switch (map[h][w]) {
			case 0://벽
				printf("□");
				break;

			case 1://빈공간
				printf("  ");
				break;

			case 2://생성된 블럭
				printf("■");
				break;

			case 3://멈춰진 블럭
				printf("▣");
				break;

			default:
				break;
			}
		}
		printf("\n");
	}

	return 0;
}

int map2view2() {	//맵을 그려주는 함수
	for (int h = 0; h < HIGHT; h = h + 1) {
		for (int w = 0; w < WIDE; w = w + 1) {
			if (map[h][w] != map_c[h][w]) {
				gotoxy(w + 2, h + 2);
				switch (map[h][w]) {
				case WALL://벽
					printf("□");
					break;

				case EMPTY://빈공간
					printf("  ");
					break;

				case ACTIVE_BLOCK://생성된 블럭
					printf("■");
					break;

				case INACTIVE_BLOCK://멈춰진 블럭
					printf("▣");
					break;

				default:
					break;
				}
			}
		}
	}

	for (int h = 0; h < HIGHT; h = h + 1) {
		for (int w = 0; w < WIDE; w = w + 1) {
			map_c[h][w] = map[h][w];
		}
	}
}

void gotoxy(int x, int y) {	//좌표 지정 함수
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int block2map(int blocks[][3][3], int x, int y, int b_offset) {
	for (int h = y; h < y + 3; h = h + 1) {
		for (int w = x + 5; w < x + 8; w = w + 1) {
			if (map[h][w] == ACTIVE_BLOCK) {
				map[h][w] = EMPTY;
			}
			if (map[h][w] == EMPTY) {
				map[h][w] = blocks[b_offset][h - y][w - x - 5];
			}
		}
	}

	return 0;
}

int check_block() {
	for (int w = 1; w < WIDE - 1; w++)
	{
		if (map[1][w] == INACTIVE_BLOCK)
			return 1;

	}
	return 0;
}


int block2down2check() {
	for (int h = HIGHT; h > 1; h = h - 1) {
		for (int w = 1; w < WIDE - 1; w = w + 1) {
			if (map[h - 2][w] == 2) {
				if (map[h - 1][w] == WALL || map[h - 1][w] == INACTIVE_BLOCK) {
					return 0;
				}
			}
		}
	}

	return 1;
}

int block2move2check(int x, int y, int left) {
	switch (left) {
	case 0:
		for (int h = y; h < y + 3; h = h + 1) {
			for (int w = x + 5; w < x + 8; w = w + 1) {
				if (map[h][w] == 2 && (map[h][w - 1] == WALL || map[h][w - 1] == INACTIVE_BLOCK)) {
					return 0;
				}
			}
		}
		break;

	case 1:
		for (int h = y; h < y + 3; h = h + 1) {
			for (int w = x + 5; w < x + 8; w = w + 1) {
				if (map[h][w] == ACTIVE_BLOCK && (map[h][w + 1] == WALL || map[h][w + 1] == INACTIVE_BLOCK)) {
					return 0;
				}
			}
		}
		break;
	}

	return 1;
}

int block2rotate2check(int blocks[][3][3], int x, int y, int b_offset) {
	for (int h = y; h < y + 3; h = h + 1) {
		for (int w = x + 5; w < x + 8; w = w + 1) {
			if ((map[h][w] == WALL || map[h][w] == INACTIVE_BLOCK) && blocks[(b_offset + 1) % 4][h - y][w - x - 5] == ACTIVE_BLOCK) {
				return 0;
			}
		}
	}
	return 1;
}

int block2erase2check() {
	for (int h = HIGHT - 2; h > 1; h = h - 1) {
		int lineinblock = 0;
		for (int w = 1; w < WIDE - 1; w = w + 1) {
			if (map[h][w] == 3) {
				lineinblock = lineinblock + 1;
			}
		}

		if (lineinblock == (WIDE - 2)) {
			block2eraseline(h);
			total_e_line = total_e_line + 1;
			h = HIGHT - 2;
		}
	}

	return 1;
}

int block2eraseline(int line_n) {
	for (int w = 1; w < WIDE - 1; w = w + 1) {
		map[line_n][w] = 1;
	}

	for (int h = line_n; h > 1; h = h - 1) {
		for (int w = 1; w < WIDE - 1; w = w + 1) {
			if (map[h - 1][w] == INACTIVE_BLOCK || map[h - 1][w] == EMPTY) {
				map[h][w] = map[h - 1][w];
			}
		}
	}

	return 0;
}

int block2down(int x, int y) {
	for (int h = y + 3 - 1; h > y - 1 - 1; h = h - 1) {
		for (int w = x + 5; w < x + 5 + 3; w = w + 1) {
			if (map[h][w] == ACTIVE_BLOCK || map[h][w] == EMPTY) {
				if (map[h + 1][w] == ACTIVE_BLOCK || map[h + 1][w] == EMPTY) {
					map[h + 1][w] = map[h][w];
				}
			}
		}
	}

	for (int w = 1; w < WIDE - 1; w = w + 1) {
		if (map[y][w] == ACTIVE_BLOCK) {
			map[y][w] = EMPTY;
		}
	}

	return 0;
}

int block2down2done() {
	for (int h = 1; h < HIGHT; h = h + 1) {
		for (int w = 1; w < WIDE - 1; w = w + 1) {
			map[h][w] = (map[h][w] == ACTIVE_BLOCK) ? INACTIVE_BLOCK : map[h][w];
		}
	}

	return 0;
}

int block2move2done(int x, int y, int left) {
	switch (left) {
	case 0:
		for (int h = 0; h < 3; h = h + 1) {
			if (map[y + h][x + 2 + 5] == ACTIVE_BLOCK) {
				map[y + h][x + 3 + 5] = EMPTY;
			}
		}
		break;

	case 1:
		for (int h = 0; h < 3; h = h + 1) {
			if (map[y + h][x + 5] == 2) {
				map[y + h][x - 1 + 5] = 1;
			}
		}
		break;
	}
}
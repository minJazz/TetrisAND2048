#pragma once
#define XINFOR 25
#define YINFOR 4
float delay = 350;
int ddown = 1;

int level = 0;
int x = 0;
int y = 1;
int offset = 0;
int blocks_n = 0;
clock_t start;
void game_infor();
void CursorHide(char show) {
	HANDLE hCorsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hCorsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hCorsole, &ConsoleCursor);
	system("pause>null");
}

int get_key() {
	if (_kbhit()) {
		switch (getch()) {

		case 32://스페이스바: 팍 내리기
			delay = (20 * level) + 1;
			ddown = 1;
			break;
		case 80:
		case 112:
			gotoxy(XINFOR, YINFOR - 3);
			printf("다시하기 : P");
			gotoxy(XINFOR, YINFOR - 2);
			printf("새 게임 : N");
			gotoxy(XINFOR, YINFOR - 1);
			printf("게임 종료 : ESC");
			switch (getch()) {
			case 27:
				system("cls");
				return 0;
				break;
			case 78:
			case 110:
				system("cls");
				return 2;
				break;
			}
			break;
		case 224:
			switch (getch()) {
			case 72://위:돌리기
				switch (block2rotate2check(blocks[blocks_n], x, y, offset)) {
				case 1:
					offset = (offset + 1) % 4;
					block2map(blocks[blocks_n], x, y, offset);
					break;
				case 0:
					break;
				}
				break;

			case 80://아래
				delay = 100;
				break;

			case 75://왼쪽:이동
				switch (block2move2check(x, y, 0)) {
				case 1:
					if (-6 < --x) {
						block2map(blocks[blocks_n], x, y, offset);
						block2move2done(x, y, 0);
					}
					else {
						x++;
					}
					break;
				case 0:
					break;
				}
				break;

			case 77://오른쪽:이동
				switch (block2move2check(x, y, 1)) {
				case 1:
					if (++x < 6) {
						block2map(blocks[blocks_n], x, y, offset);
						block2move2done(x, y, 1);
					}
					else {
						x--;
					}
					break;
				case 0:
					break;
				}
				break;
			}
		default:
			break;
		}

	}

	map2view2();
	return 1;
}
int block_Down() {
	if ((clock() - start) > delay - (20 * level)) {
		start = clock();
		switch (block2down2check()) {
		case 0://더이상 못내림


			block2down2done();
			if (check_block()) {
				gotoxy(30, 20);
				printf("***Game Over***");
				Sleep(2000);
				return 0;
			}
			x = 0; y = 1; offset = 0;
			blocks_n = rand() % 7;
			block2map(blocks[blocks_n], x, y, offset);
			map2view2();
			block2erase2check();
			level = (total_e_line / 10) + 1;
			delay = 350;
			ddown = 0;
			break;

		case 1://내리기 가능
			block2down(x, y);
			y = y + 1;
			if (ddown == 0) {
				delay = 350;
			}
			break;
		}
	}
	return 1;
}



void game_infor()
{
	gotoxy(XINFOR, YINFOR + 1); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(XINFOR, YINFOR + 2); printf("■ 조작법: 회전                                   ■");
	gotoxy(XINFOR, YINFOR + 3); printf("■          ▲               space bar: 수직하강  ■");
	gotoxy(XINFOR, YINFOR + 4); printf("■왼쪽이동◀  ▶오른쪽이동       'P'or'p': pause  ■");
	gotoxy(XINFOR, YINFOR + 5); printf("■          ▼                                    ■");
	gotoxy(XINFOR, YINFOR + 6); printf("■       아래이동                                 ■");
	gotoxy(XINFOR, YINFOR + 7); printf("■                                                ■");
	gotoxy(XINFOR, YINFOR + 8); printf("■   현재레벨:%d                                   ■", level);
	gotoxy(XINFOR, YINFOR + 9); printf("■                                                ■");
	gotoxy(XINFOR, YINFOR + 10); printf("■   현재점수: %d                                  ■", total_e_line);
	gotoxy(XINFOR, YINFOR + 11); printf("■                                                ■");
	gotoxy(XINFOR, YINFOR + 12); printf("■                                                ■");
	gotoxy(XINFOR, YINFOR + 13); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■");
}

int print_tetris_first() {
	gotoxy(15, 5);	printf("■■■   ■■■    ■■■    ■■    ■    ■■■");
	gotoxy(15, 6);	printf("  ■     ■          ■      ■ ■   ■    ■    ");
	gotoxy(15, 7);	printf("  ■     ■■■      ■      ■■■  ■    ■■■");
	gotoxy(15, 8);	printf("  ■     ■          ■      ■ ■   ■        ■");
	gotoxy(15, 9);	printf("  ■     ■■■      ■      ■  ■  ■    ■■■");
	gotoxy(20, 13);	printf("'방향키를 누르면 실행합니다'");

	getch();
}
int tetris_start() {
	int input;
	print_tetris_first();
	if (_kbhit()) {
		system("cls");
		init_map();
		srand((unsigned)time(NULL));



		level = 0;
		blocks_n = (rand() % 1);

		start = clock();

		block2map(blocks[blocks_n], x, y, offset);
		map2view();

		while (1) {
			gotoxy(0, 27);
			printf("x=%d,y=%d,b_offset=%d,time=%.1f  ", x, y, offset, (float)(clock() - start));
			game_infor();
			//gotoxy(25, 7);
			//printf("Level : %d", level);
			//gotoxy(25, 8);
			//printf("점수 : %d  ", total_e_line);

			gotoxy(25, 10);

			if (!block_Down()) {
				return 0;
			}

			switch (get_key()) {
			case 0:
				return 0;
				break;

			case 2:
				system("cls");
				tetris_start();
				break;
			}




		}
	}

	return 0;
}
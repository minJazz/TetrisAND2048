#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 57
#define P 112
#define N 110

int Board[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
int checkBoard[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
int key;
int score = 8000;
void UI();
void Press();
void newgame();
void New();
void Random_number();
void Random_number_or();
void Down();
void Up();
void Right();
void Left();
void check();
void action(int code);
void draw();
void play_2048();

void play_2048() {
	Press();
	newgame();

	draw();

}




void UI()
{
	system("cls");
	int i, j;
	//	printf("												시작   점수 : 10000\n\n");
	//	printf(" 												진행된 시간 : 24m 30s  \n\n	");
	printf("\n\n\n\n												N : 초기화  P : 일시정지 \n\n");
	for (i = 0; i < 4; i++) {
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n■                                                                  ■\n■                                                                  ■\n■                                                                  ■\n■");
		for (j = 0; j < 4; j++) {
			if (Board[i][j] == 0) printf("		.");
			else {
				printf("		%d", Board[i][j]);
			}
		}
		printf("   ■\n");
	}
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("												현재 점수 :    %d\n", score);
	//printf(" 												최고  점수 :   8750\n");
	//printf(" 												마지막  점수 : 8000\n");
	printf("\n\n\n\n\n \n\n\n\n\n");
	printf("												 ↑ : 위로\n");
	printf("										← : 왼쪽으로	 ↓ : 아래로  → : 우측으로 \n ");
}


void Press() {
	for (int i = 0; i <= 2; i++) {
		for (int i = 0; i <= 15; i++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
			system("cls");
			printf("\n\n\n");
			printf("			■■■■■■		■■■■■■			■		■■■■■■");
			printf("\n				  ■		■        ■		      ■■		■        ■");
			printf("\n				  ■		■        ■		    ■  ■		■        ■");
			printf("\n				  ■		■        ■		  ■    ■		■        ■");
			printf("\n				  ■		■        ■	        ■      ■		■        ■");
			printf("\n			■■■■■■		■        ■	      ■■■■■■■		■■■■■■");
			printf("\n			■			■        ■			■		■        ■");
			printf("\n			■			■        ■			■		■        ■");
			printf("\n			■			■        ■			■		■        ■");
			printf("\n			■			■        ■			■		■        ■");
			printf("\n			■■■■■■		■■■■■■			■		■■■■■■");
		}
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n						<아무키나 입력하세요>\n");
	//while (!kbhit());
}
void newgame()
{
	srand(time(NULL));
	int x = (rand() % 4) + 1, y = (rand() % 4) + 1;
	for (int i = 0; i < 2; i++)

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				Board[i][j] = 0;
	Board[x][y] = 2;
}
void New()
{
	int Board[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	newgame();
}
void Random_number()
{
	int num1, num2, add;
	int cnt = 0;
	srand((unsigned)time(NULL));
	num1 = (rand() % 4);
	num2 = (rand() % 4);

	if ((num1 + num2) < 5)
	{
		add = 2;
	}
	else
	{
		add = 4;
	}

	while (1)
	{
		if (Board[num1][num2] == 0)
		{
			Board[num1][num2] = add;
			break;
		}
		else
		{
			srand((unsigned)time(NULL));
			num1 = (rand() % 4);
			num2 = (rand() % 4);
		}
	}
}

void Random_number_or()
{
	srand(time(NULL));
	int nu = (rand() % 2) + 1;
	if (nu == 1)
		Random_number();
	else {
		Random_number();
		Random_number();
	}
}
void Down()
{
	int i, j;
	for (j = 0; j < 4; j++)
	{
		i = 2;
		while (1)
		{
			while (Board[i][j] == 0)
			{
				if (i == -1)
					break;
				i--;
			}
			if (i == -1)
				break;
			while (i < 3 && (Board[i + 1][j] == 0 || Board[i][j] == Board[i + 1][j]))
			{
				Board[i + 1][j] += Board[i][j];
				Board[i][j] = 0;
				i++;
			}
			i--;
		}
	}
}
void Up()
{
	int i, j;
	for (j = 0; j < 4; j++)
	{
		i = 1;
		while (1)
		{
			while (Board[i][j] == 0)
			{
				if (i == 4)
					break;
				i++;
			}
			if (i == 4)
				break;
			while (i > 0 && (Board[i - 1][j] == 0 || Board[i][j] == Board[i - 1][j]))
			{
				Board[i - 1][j] += Board[i][j];
				Board[i][j] = 0;
				i--;
			}
			i++;
		}
	}
}


void Right()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		j = 2;
		while (1)
		{
			while (Board[i][j] == 0)
			{
				if (j == -1)
					break;
				j--;
			}
			if (j == -1)
				break;

			while (j < 3 && (Board[i][j + 1] == 0 || Board[i][j] == Board[i][j + 1]))
			{
				Board[i][j + 1] += Board[i][j];
				Board[i][j] = 0;
				j++;
			}
			j--;
		}

	}
}
void Left()
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		j = 1;
		while (1)
		{
			while (Board[i][j] == 0)
			{
				if (j == 4)
					break;
				j++;
			}
			if (j == 4)
				break;
			while (j > 0 && (Board[i][j - 1] == 0 || Board[i][j] == Board[i][j - 1]))
			{
				Board[i][j - 1] += Board[i][j];
				Board[i][j] = 0;
				j--;
			}
			j++;
		}
	}
}

void check()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			checkBoard[i][j] = Board[i][j];
		}
	}

}

void action(int code)
{
	int i = 0;
	int j = 0;

	switch (code)
	{
	case UP:
	{
		check();
		Up();

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (checkBoard[i][j] != Board[i][j])
				{
					Random_number_or();
					score--;
					return;
				}
			}
		}


		break;
	}
	case DOWN:
	{
		check();
		Down();

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (checkBoard[i][j] != Board[i][j])
				{
					Random_number_or();
					score--;
					return;


				}
			}
		}
		break;
	}
	case LEFT:
	{
		check();
		Left();

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (checkBoard[i][j] != Board[i][j])
				{
					Random_number_or();
					score--;
					return;


				}
			}
		}

		break;
	}
	case RIGHT:
	{
		check();
		Right();

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (checkBoard[i][j] != Board[i][j])
				{
					Random_number_or();
					score--;
					return;

				}
			}
		}

		break;
	}
	case P:
	{
		printf("PAUSE");
		system("PAUSE");
		break;
	}
	case N:
	{
		New();
		break;
	}

	default:
	{
		printf("잘못입력하엿습니다\n다시입력해주십시오\n");
		printf("%d", code);
		system("pause");
		return;
	}
	}
}

void draw()
{
	char code;
	int aro;
	code = 0;
	while (code != ESC)
	{
		UI();

		fflush(stdin);
		code = _getch();
		if (code == 224 || code == -32)
		{
			code = _getch();
		}
		action(code);
	}
}

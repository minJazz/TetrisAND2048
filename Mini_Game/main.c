
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <Windows.h>



#include <conio.h>
#include <ctype.h>
#include <process.h>
#include <math.h>



#include "2048.h"
#include "init_mapping.h"
#include "blocks.h"
#include "tetris.h"
void print_menu();
int Main_menu(int num);
void menu_choice();


int menu = 8;

int main() {



	CursorHide(0);
	print_menu();
	while (1) {
		menu_choice();
	}

	return 0;
}





void menu_choice() {

	switch (menu = Main_menu(menu)) {
	case 10:
		system("cls");
		tetris_start();

		system("cls");
		print_menu();
		break;
	case 20:
		system("cls");
		play_2048();
		system("cls");
		print_menu();
		break;
	case 30:

		exit(0);

	case 1:
		gotoxy(36, 18); printf("¢¸");
		gotoxy(36, 20); printf("  ");
		gotoxy(36, 22); printf("  "); break;

	case 2:
		gotoxy(36, 18); printf("  ");
		gotoxy(36, 20); printf("¢¸");
		gotoxy(36, 22); printf("  "); break;
	case 3:
		gotoxy(36, 18); printf("  ");
		gotoxy(36, 20); printf("  ");
		gotoxy(36, 22); printf("¢¸"); break;


	}
}
void print_menu() {
	gotoxy(14, 1); printf("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à");
	gotoxy(14, 2); printf("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à");
	gotoxy(14, 3); printf("¡à¡à¡á      ¡á  ¡á¡á¡á  ¡á    ¡á  ¡á¡á¡á                            ¡à¡à");
	gotoxy(14, 4); printf("¡à¡à¡á¡á  ¡á¡á    ¡á    ¡á¡á  ¡á    ¡á                              ¡à¡à");
	gotoxy(14, 5); printf("¡à¡à¡á  ¡á  ¡á    ¡á    ¡á  ¡á¡á    ¡á                              ¡à¡à");
	gotoxy(14, 6); printf("¡à¡à¡á      ¡á  ¡á¡á¡á  ¡á    ¡á  ¡á¡á¡á                            ¡à¡à");
	gotoxy(14, 7); printf("¡à¡à                                                                ¡à¡à");
	gotoxy(14, 8); printf("¡à¡à                                                                ¡à¡à");
	gotoxy(14, 9); printf("¡à¡à                      ¡á¡á¡á¡á¡á    ¡á¡á    ¡á      ¡á  ¡á¡á¡á  ¡à¡à");
	gotoxy(14, 10); printf("¡à¡à                      ¡á          ¡á    ¡á  ¡á¡á  ¡á¡á  ¡á      ¡à¡à");
	gotoxy(14, 11); printf("¡à¡à                      ¡á  ¡á¡á¡á  ¡á¡á¡á¡á  ¡á  ¡á  ¡á  ¡á¡á¡á  ¡à¡à");
	gotoxy(14, 12); printf("¡à¡à                      ¡á    ¡á¡á  ¡á    ¡á  ¡á      ¡á  ¡á      ¡à¡à");
	gotoxy(14, 13); printf("¡à¡à                      ¡á¡á¡á¡á¡á  ¡á    ¡á  ¡á      ¡á  ¡á¡á¡á  ¡à¡à");
	gotoxy(14, 14); printf("¡à¡à                                                                ¡à¡à");
	gotoxy(14, 15); printf("¡à¡à                                                                ¡à¡à");
	gotoxy(14, 16); printf("¡à¡à                                                                ¡à¡à");
	gotoxy(14, 17); printf("¡à¡à                                                                ¡à¡à");
	gotoxy(14, 18); printf("¡à¡à                          1.TETRIS                              ¡à¡à");
	gotoxy(14, 19); printf("¡à¡à                                                                ¡à¡à");
	gotoxy(14, 20); printf("¡à¡à                          2. 2048                               ¡à¡à");
	gotoxy(14, 21); printf("¡à¡à                                                                ¡à¡à");
	gotoxy(14, 22); printf("¡à¡à                          3. EXIT                               ¡à¡à");
	gotoxy(14, 23); printf("¡à¡à                                                                ¡à¡à");
	gotoxy(14, 24); printf("¡à¡à                                                                ¡à¡à");
	gotoxy(14, 25); printf("¡à¡à                                                                ¡à¡à");
	gotoxy(14, 26); printf("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à");
	gotoxy(14, 27); printf("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à\n\n\n");
}
int Main_menu(int menu)
{
	switch (getch()) {


	case 13:
		return menu * 10;
		break;
	case 224:
		switch (getch()) {
		case 72:

			return (menu % 3) + 1;
			break;

		case 80:
			return (menu % 3) + 1;
			break;


		}

	default:
		break;
	}



	return 0;
}
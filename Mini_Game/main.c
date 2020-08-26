
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
		gotoxy(36, 18); printf("ขธ");
		gotoxy(36, 20); printf("  ");
		gotoxy(36, 22); printf("  "); break;

	case 2:
		gotoxy(36, 18); printf("  ");
		gotoxy(36, 20); printf("ขธ");
		gotoxy(36, 22); printf("  "); break;
	case 3:
		gotoxy(36, 18); printf("  ");
		gotoxy(36, 20); printf("  ");
		gotoxy(36, 22); printf("ขธ"); break;


	}
}
void print_menu() {
	gotoxy(14, 1); printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ");
	gotoxy(14, 2); printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ");
	gotoxy(14, 3); printf("กเกเกแ      กแ  กแกแกแ  กแ    กแ  กแกแกแ                            กเกเ");
	gotoxy(14, 4); printf("กเกเกแกแ  กแกแ    กแ    กแกแ  กแ    กแ                              กเกเ");
	gotoxy(14, 5); printf("กเกเกแ  กแ  กแ    กแ    กแ  กแกแ    กแ                              กเกเ");
	gotoxy(14, 6); printf("กเกเกแ      กแ  กแกแกแ  กแ    กแ  กแกแกแ                            กเกเ");
	gotoxy(14, 7); printf("กเกเ                                                                กเกเ");
	gotoxy(14, 8); printf("กเกเ                                                                กเกเ");
	gotoxy(14, 9); printf("กเกเ                      กแกแกแกแกแ    กแกแ    กแ      กแ  กแกแกแ  กเกเ");
	gotoxy(14, 10); printf("กเกเ                      กแ          กแ    กแ  กแกแ  กแกแ  กแ      กเกเ");
	gotoxy(14, 11); printf("กเกเ                      กแ  กแกแกแ  กแกแกแกแ  กแ  กแ  กแ  กแกแกแ  กเกเ");
	gotoxy(14, 12); printf("กเกเ                      กแ    กแกแ  กแ    กแ  กแ      กแ  กแ      กเกเ");
	gotoxy(14, 13); printf("กเกเ                      กแกแกแกแกแ  กแ    กแ  กแ      กแ  กแกแกแ  กเกเ");
	gotoxy(14, 14); printf("กเกเ                                                                กเกเ");
	gotoxy(14, 15); printf("กเกเ                                                                กเกเ");
	gotoxy(14, 16); printf("กเกเ                                                                กเกเ");
	gotoxy(14, 17); printf("กเกเ                                                                กเกเ");
	gotoxy(14, 18); printf("กเกเ                          1.TETRIS                              กเกเ");
	gotoxy(14, 19); printf("กเกเ                                                                กเกเ");
	gotoxy(14, 20); printf("กเกเ                          2. 2048                               กเกเ");
	gotoxy(14, 21); printf("กเกเ                                                                กเกเ");
	gotoxy(14, 22); printf("กเกเ                          3. EXIT                               กเกเ");
	gotoxy(14, 23); printf("กเกเ                                                                กเกเ");
	gotoxy(14, 24); printf("กเกเ                                                                กเกเ");
	gotoxy(14, 25); printf("กเกเ                                                                กเกเ");
	gotoxy(14, 26); printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ");
	gotoxy(14, 27); printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n\n\n");
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
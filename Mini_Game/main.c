
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
		gotoxy(36, 18); printf("��");
		gotoxy(36, 20); printf("  ");
		gotoxy(36, 22); printf("  "); break;

	case 2:
		gotoxy(36, 18); printf("  ");
		gotoxy(36, 20); printf("��");
		gotoxy(36, 22); printf("  "); break;
	case 3:
		gotoxy(36, 18); printf("  ");
		gotoxy(36, 20); printf("  ");
		gotoxy(36, 22); printf("��"); break;


	}
}
void print_menu() {
	gotoxy(14, 1); printf("�������������������������������������");
	gotoxy(14, 2); printf("�������������������������������������");
	gotoxy(14, 3); printf("����      ��  ����  ��    ��  ����                            ���");
	gotoxy(14, 4); printf("�����  ���    ��    ���  ��    ��                              ���");
	gotoxy(14, 5); printf("����  ��  ��    ��    ��  ���    ��                              ���");
	gotoxy(14, 6); printf("����      ��  ����  ��    ��  ����                            ���");
	gotoxy(14, 7); printf("���                                                                ���");
	gotoxy(14, 8); printf("���                                                                ���");
	gotoxy(14, 9); printf("���                      ������    ���    ��      ��  ����  ���");
	gotoxy(14, 10); printf("���                      ��          ��    ��  ���  ���  ��      ���");
	gotoxy(14, 11); printf("���                      ��  ����  �����  ��  ��  ��  ����  ���");
	gotoxy(14, 12); printf("���                      ��    ���  ��    ��  ��      ��  ��      ���");
	gotoxy(14, 13); printf("���                      ������  ��    ��  ��      ��  ����  ���");
	gotoxy(14, 14); printf("���                                                                ���");
	gotoxy(14, 15); printf("���                                                                ���");
	gotoxy(14, 16); printf("���                                                                ���");
	gotoxy(14, 17); printf("���                                                                ���");
	gotoxy(14, 18); printf("���                          1.TETRIS                              ���");
	gotoxy(14, 19); printf("���                                                                ���");
	gotoxy(14, 20); printf("���                          2. 2048                               ���");
	gotoxy(14, 21); printf("���                                                                ���");
	gotoxy(14, 22); printf("���                          3. EXIT                               ���");
	gotoxy(14, 23); printf("���                                                                ���");
	gotoxy(14, 24); printf("���                                                                ���");
	gotoxy(14, 25); printf("���                                                                ���");
	gotoxy(14, 26); printf("�������������������������������������");
	gotoxy(14, 27); printf("�������������������������������������\n\n\n");
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
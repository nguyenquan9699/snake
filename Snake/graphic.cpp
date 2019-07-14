// Draw the frame of the game

#include "graphic.h"

void AdjustSpeed(int *speed, int x, int y);
void DrawFrame()
{
	setcolor(11);
	// The top frame  
	for (int i = leftFrame; i <= rightFrame; i++)
	{
		Gotoxy(i, upFrame);
		printf("%c", 220); // ▄ 
	}
	// The bottom frame
	for (int i = leftFrame; i <= rightFrame; i++)
	{
		Gotoxy(i, downFrame);
		printf("%c", 223); // ▀ 
	}
	// The left frame
	for (int i = upFrame + 1; i < downFrame; i++)
	{
		Gotoxy(leftFrame, i);
		printf("%c", 219); // ▀ 
	}
	// The right frame
	for (int i = upFrame + 1; i < downFrame; i++)
	{
		Gotoxy(rightFrame, i);
		printf("%c", 219); // ▀ 
	}
	setcolor(7);
}
// Highscore
void DrawHighscore(int highscore) {
	setcolor(6);
	Gotoxy(78, 5);
	printf("Highscore: %d", highscore);
	setcolor(7);
}

// Score
void DrawScore(int score) {
	setcolor(6);
	Gotoxy(78, 7);
	printf("Score: %d", score);
	setcolor(7);
}
// Menu

void Authors(int x, int y) {
	setcolor(6);
	Gotoxy(x, y);
	printf("Authors");
	Gotoxy(x, y + 1);
	printf("1. Nguyen Minh Quan");
	Gotoxy(x, y + 2);
	printf("2. Tran Dinh Khoat");
	setcolor(7);
}
void DrawPlay(int color) {
	setcolor(color);
	Gotoxy(42, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 187, 203, 0, 0, 201, 205, 187, 203, 0, 203);
	Gotoxy(42, 18);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 188, 186, 0, 0, 204, 205, 185, 200, 203, 188);
	Gotoxy(42, 19);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 202, 0, 0, 202, 205, 188, 202, 0, 202, 0, 202, 0);
	setcolor(7);
}
void DrawExit(int color) {
	setcolor(color);
	Gotoxy(66, 17);
	printf("%c%c%c%c%c%c%c%c%c%c", 201, 205, 187, 201, 203, 187, 203, 201, 203, 187);
	Gotoxy(66, 18);
	printf("%c%c%c%c%c%c%c%c%c%c", 186, 185, 0, 201, 202, 187, 186, 0, 186, 0);
	Gotoxy(66, 19);
	printf("%c%c%c%c%c%c%c%c%c%c", 200, 205, 188, 202, 0, 200, 202, 0, 202, 0);
	setcolor(7);
}
void DrawMenu()
{
	setcolor(3);
	char chu[7][67];
	strcpy(chu[0], "      ::::::::   ::::    :::      :::      :::    :::  :::::::::: ");
	strcpy(chu[1], "    :+:    :+:  :+:+:   :+:    :+: :+:    :+:   :+:   :+:         ");
	strcpy(chu[2], "   +:+         :+:+:+  +:+   +:+   +:+   +:+  +:+    +:+          ");
	strcpy(chu[3], "  +#++:++#++  +#+ +:+ +#+  +#++:++#++:  +#++:++     +#++:++#      ");
	strcpy(chu[4], "        +#+  +#+  +#+#+#  +#+     +#+  +#+  +#+    +#+            ");
	strcpy(chu[5], "#+#    #+#  #+#   #+#+#  #+#     #+#  #+#   #+#   #+#             ");
	strcpy(chu[6], "########   ###    ####  ###     ###  ###    ###  ##########       ");
	Gotoxy(30, 7);
	puts(chu[0]);
	Gotoxy(30, 8);
	puts(chu[1]);
	Gotoxy(30,  9);
	puts(chu[2]);
	Gotoxy(30, 10);
	puts(chu[3]);
	Gotoxy(30, 11);
	puts(chu[4]);
	Gotoxy(30, 12);
	puts(chu[5]);
	Gotoxy(30, 13);
	puts(chu[6]);
	setcolor(7);
	DrawPlay(4);
	DrawExit(7);
}

void Menu(int *speed)
{
	DrawMenu();
	int chon = 1;
	while (true)
	{
		char lenh = _getch();
		if (lenh == 13) {
			if (chon == 2) exit(0);
			system("cls");
			return;
		}
		if ((lenh == 'a' || lenh == 0x4B) && chon == 2) {
			chon--;
			DrawPlay(4);
			DrawExit(7);
			continue;
		}
		if ((lenh == 'd' || lenh == 0x4D) && chon == 1) {
			chon++;
			DrawPlay(7);
			DrawExit(4);
			continue;
		}
		if (lenh == ' ') {
			AdjustSpeed(&*speed, 55, 22);
			continue;
		}
	}
}
void DrawInstruction(int x, int y) {
	setcolor(3);
	Gotoxy(x, y);
	printf("_ Press d to TURN RIGHT");
	Gotoxy(x, y + 1);
	printf("_ Press a to TURN LEFT");
	Gotoxy(x, y + 2);
	printf("_ Press space to PAUSE and ADJUST SPEED");
	setcolor(7);
}
void DrawPlayagain(int color) {
	setcolor(color);
	Gotoxy(49, 16);
	printf("AGAIN");
	setcolor(7);
}
void DrawEndExit(int color) {
	setcolor(color);
	Gotoxy(66, 16);
	printf("EXIT");
	setcolor(7);
}
void DrawGameOver()
{
	setcolor(3);
	system("cls");
	Gotoxy(46, 12);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 187, 201, 205, 187, 201, 203, 187, 201, 205, 187, 0, 0, 201, 205, 187, 203, 0, 0, 203, 201, 205, 187, 203, 205, 187);
	Gotoxy(46, 13);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 0, 203, 204, 205, 185, 186, 186, 186, 186, 185, 0, 0, 0, 186, 0, 186, 200, 187, 201, 188, 186, 185, 0, 204, 203, 188);
	Gotoxy(46, 14);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 188, 202, 0, 202, 202, 0, 202, 200, 205, 188, 0, 0, 200, 205, 188, 0, 200, 188, 0, 200, 205, 188, 202, 200, 205);
	setcolor(7);
	DrawPlayagain(4);
	DrawEndExit(7);
}

void MenuEnd(int *speed)
{
	DrawGameOver();
	int chon = 1;
	while (true)
	{
		char lenh = _getch();
		if (lenh == 13) {
			if (chon == 2) exit(0);
			system("cls");
			return;
		}
		if (lenh == 0x4B && chon == 2) {
			chon--;
			DrawPlayagain(4);
			DrawEndExit(7);
			continue;
		}
		if (lenh == 0x4D && chon == 1) {
			chon++;
			DrawPlayagain(7);
			DrawEndExit(4);
			continue;
		}
		if (lenh == ' ') {
			AdjustSpeed(&*speed, 55, 20);
			continue;
		}
	}
}
void DrawAdjust(int x, int y, int level) {
	Gotoxy(x, y - 1);
	printf("%c%c%cSPEED%c%c",175,175,175,175,175);
	Gotoxy(x, y + 2);
	setcolor(level);
	switch (level) {
	case 1:printf(" so slow! "); break;
	case 2:printf("   easy   "); break;
	case 3:printf("  normal  "); break;
	case 4:printf("   hard   "); break;
	case 5:printf("  insane  "); break;
	case 6:printf("impossible"); break;
	}
	Gotoxy(x, y);
	setcolor(7);
	printf("%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177);
	setcolor(7);
	Gotoxy(x, y);
	printf("%c", 176);
	Gotoxy(x + 9, y);
	printf("%c", 176);
	for (int i = 1; i <= level; i++) {
		Gotoxy(x + i, y);
		setcolor(i);
		printf("%c%c%c", 219, 219, 219);
	}
	setcolor(7);
}
void AdjustSpeed(int *speed, int x, int y) {
	int level;
	switch (*speed) {
	case Speed1:level = 1; break;
	case Speed2:level = 2; break;
	case Speed3:level = 3; break;
	case Speed4:level = 4; break;
	case Speed5:level = 5; break;
	case Speed6:level = 6; break;
	}
	while (true) {
		DrawAdjust(x, y, level);
		char c = _getch();
		if ((c == 'd' || c == 0x4D) && *speed != Speed6) {
			*speed /= 2;
			level++;
		}
		if ((c == 'a' || c == 0x4B) && *speed != Speed1) {
			*speed *= 2;
			level--;
		}	
		if (c == ' ') {
			Gotoxy(x, y);
			printf("           ");
			Gotoxy(x, y + 2);
			printf("           ");
			Gotoxy(x, y - 1);
			printf("           ");
			break;
		}
	}
}
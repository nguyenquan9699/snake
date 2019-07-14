#pragma once
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Direction
#define left -2
#define right 2
#define up -1
#define down 1
// Object
#define head 2
#define body 1
#define food -1

// Frame
#define upFrame 2
#define downFrame 27
#define leftFrame 4
#define rightFrame 75
#define width ((rightFrame - leftFrame - 1) / 2)
#define height (downFrame - upFrame - 1)
// Control
#define RightKey 'd'
#define LeftKey 'a'
// Level
#define Speed1 800
#define Speed2 400
#define Speed3 200
#define Speed4 100
#define Speed5 50
#define Speed6 25
struct Objects
{
	int X;
	int Y;
	int object;
};
void Gotoxy(int x, int y);
void HidePointer();
void ShowPointer();
bool SP(Objects a, Objects b);
void setcolor(WORD color);
#include "snake.h"

void DrawSnake(Objects &Head, Objects Body[], int length) {
	Gotoxy((Head.X - 1) * 2 + leftFrame + 1, Head.Y + upFrame);
	setcolor(4);
	printf("%c%c", 219, 219);
	setcolor(7);
	for (int i = 1; i <= length; i++) {
		Gotoxy((Body[i].X - 1) * 2 + leftFrame + 1, Body[i].Y + upFrame);
		printf("%c%c", 219, 219);
	}
}
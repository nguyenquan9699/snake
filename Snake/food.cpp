#include "food.h"

void Appear() {
	setcolor(14);
	printf("%c%c", 219, 219);
	setcolor(7);
}
void Appearence(int board[][height+1], Objects &Food) {
	srand(time(0));
	do
	{
		int x = rand() % width;
		int y = rand() % height;
		if (x == 0) x += width;
		if (y == 0) y += height;
		if (board[x][y] != 0) continue;
		else {
			board[x][y] = food;
			Food.X = x; Food.Y = y;
			Gotoxy((x - 1)*2 + leftFrame + 1, y + upFrame);
			Appear();
			break;
		}
	} while (true);
}

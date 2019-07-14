#include "gameplay.h"

void Eat(int &score,Objects Food, Objects Head, Objects Body[], int &length) {
	score++;
	length++;
	for (int i = length; i >= 2; i--) {
		Body[i] = Body[i - 1];
	}
	
	Body[1].X = Head.X; Body[1].Y = Head.Y;
	Head.X = Food.X; Head.Y = Food.Y;	
}
void Die(int highscore, int score) {
	SaveHighscore(highscore);
	system("cls");
	printf("Game over...\n");
}
void MoveAndDie(int &out, int score, int highscore, int direction, Objects &SnakeHead, Objects SnakeBody[], int Bodylength, int board[][height + 1]	) {
	Gotoxy((SnakeBody[Bodylength].X - 1) * 2 + leftFrame + 1, SnakeBody[Bodylength].Y + upFrame); 
	printf("  "); 
	board[SnakeBody[Bodylength].X][SnakeBody[Bodylength].Y] = 0; // Ho tro cho phan hien thuc an	
	for (int i = Bodylength; i >= 2; i--) {
		SnakeBody[i] = SnakeBody[i - 1];
	}
	SnakeBody[1].X = SnakeHead.X; SnakeBody[1].Y = SnakeHead.Y;

	if (direction == up || direction == down)
		SnakeHead.Y += direction;
	if (direction == left || direction == right)
		SnakeHead.X += direction / 2;
	board[SnakeBody[1].X][SnakeBody[1].Y] = body;
	if (board[SnakeHead.X][SnakeHead.Y] == body || SnakeHead.X < 1 || SnakeHead.X > width ||
		SnakeHead.Y < 1 || SnakeHead.Y > height) {
		out = 1;
		Die(highscore,score);
		return;
	}
	board[SnakeHead.X][SnakeHead.Y] = head; // Ho tro cho phan hien thuc an
	DrawSnake(SnakeHead, SnakeBody, Bodylength);
}

void TurnLeft(int &direction) {
	switch (direction)
	{
	case up: direction = left; break;
	case down: direction = right; break;
	case right: direction = up; break;
	case left: direction = down; break;
	}
}
void TurnRight(int &direction) {
	switch (direction)
	{
	case up: direction = right; break;
	case down: direction = left; break;
	case right: direction = down; break;
	case left: direction = up; break;
	}
}

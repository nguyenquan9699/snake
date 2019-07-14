#include "graphic.h"
#include "food.h"
#include "gameplay.h"
#include "snake.h"
#include "data.h"

int main() {
	int speed = Speed4;
	HidePointer();
	Menu(&speed);
	while (true) {
		int out = 0;
		int board[width + 1][height + 1] = {};
		int highscore = 0, score = 0, BodyLength = 1, direction = right;
		Objects SnakeHead, SnakeBody[width*height], Food;
		SnakeHead = { 12, 12, head };
		SnakeBody[1] = { 11, 12, body }; // Tinh tu 1 =>> n
		Food.object = food;
		board[11][12] = body;
		board[12][12] = head;
		LoadHighscore(highscore);		
		DrawInstruction(78, 15);
		DrawFrame();
		DrawHighscore(highscore);
		DrawScore(score);
		Authors(78, 10);

		Appearence(board, Food);
		do
		{
			int turn = 0;
			MoveAndDie(out, score, highscore, direction, SnakeHead, SnakeBody, BodyLength, board);
			if (out == 1) break;
			if (_kbhit()) {
				turn = _getch();
				// Pause
				if (turn == ' ') {
					while (true) {
						AdjustSpeed(&speed, 78, 19);
						turn = _getch();
						if (turn == ' ') break;
					}
					continue;
				}
				// Turn
				if (turn == LeftKey) TurnLeft(direction);
				if (turn == RightKey) TurnRight(direction);
			}
			if (SP(SnakeHead, Food)) {
				Eat(score, Food, SnakeHead, SnakeBody, BodyLength);
				if (score > highscore) {
					highscore = score;
					DrawHighscore(highscore);
				}
				Appearence(board, Food);
				DrawScore(score);
			}

			Sleep(speed);
		} while (true);
		system("cls");
		MenuEnd(&speed);		
	}
}
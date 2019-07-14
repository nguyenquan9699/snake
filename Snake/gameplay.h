#pragma once
#include "classic.h"
#include "food.h"
#include "snake.h"
#include "data.h"

void Eat(int &score, Objects Food, Objects Head, Objects Body[], int &length);
void Die(int highscore, int score);
void MoveAndDie(int &out, int score, int highscore, int direction, Objects &SnakeHead, Objects SnakeBody[], int Bodylength, int board[][height + 1]);
void TurnLeft(int &direction);
void TurnRight(int &direction);
void DrawGameOver();
#pragma once
#include "classic.h"

void DrawFrame();
void DrawHighscore(int highscore);
void DrawScore(int score);
void DrawMenu();
void Authors(int x, int y);
void Menu(int *speed);
void DrawInstruction(int x, int y);
void DrawExit(int color);
void DrawPlay(int color);
void DrawPlayagain(int color);
void DrawEndExit(int color);
void MenuEnd(int *speed);
void AdjustSpeed(int *speed, int x, int y);
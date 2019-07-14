#include "data.h"

void LoadHighscore(int &highscore) {
	FILE* fin = fopen("highscore.txt", "r");
	if (fin != NULL) {
		fscanf(fin, "%d", &highscore);
		fclose(fin);
	}
}
void SaveHighscore(int highscore) {
	FILE* fout = fopen("highscore.txt", "w");
	fprintf(fout, "%d", highscore);
	fclose(fout);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
bool readCsv(char * filename, double * values, int sizeX, int sizeY) {
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "File %s not found.", filename);
        return false;
    }
    int y = 0;
    char buffer[10000];
    while (fgets(buffer, 10000, file) != NULL) {
        int x = 0;
        char * start = buffer;
        while (true) {
            values[y * sizeX + x] = atof(start);
            start = strchr(start, ',');
            if (start == NULL) break;
            start += 1;
            x += 1;
            if (x >= sizeX) break;
        }
        y += 1;
        if (y >= sizeY) break;
    }
    fclose(file);
    return true;
}
double  trajet (int pos_x, int pos_y, double * tableau, double * compteur, double precipitation) {
	double h_goutte = tableau[pos_x + pos_y*100];
	double h_min = h_goutte;
	while (pos_x > -1 && pos_x < 100 && pos_y > -1 && pos_y < 100) {
		compteur[pos_x + pos_y*100] += 1;
		int y_min = 0;
		int x_min = 0;
		for (int i= -1; i<2; i++){
			for (int j= -1; j<2; j++){
				if (h_min > tableau[pos_x+i + (pos_y+j)*100]) {
					h_min = tableau[pos_x+i + (pos_y+j)*100];
					y_min = pos_y+j;
					x_min = pos_x+i;
				}
			}
		}
		pos_x = x_min;
		pos_y = y_min;
	}
	return h_min;}
int main(int argc, char * argv[]) {
    double * terrain = malloc(100 * 100 * sizeof (double));
    double * eau = malloc(100 * 100 * sizeof (double));
    readCsv("grimsel-terrain.csv", terrain, 100, 100);
    readCsv("grimsel-eau.csv", eau, 100, 100);
	double * compte = calloc(10000, sizeof (double));
	double * total = malloc(100 * 100 * sizeof (double));
	for (int j = 0; j< 100; j++) {
		for (int k = 0; k < 100; k++) {
			int result = trajet(j,k,total,compte);
		printf(" %0.f, ", compte[j+100*k]);
		}
	}
	FILE * file = fopen("grimsel-gouttes.csv", "w");
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {

            if (x > 0) fprintf(file, ", ");
            fprintf(file, "%0.f", compte[100*y +x]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    free(total);
    return 0;
}

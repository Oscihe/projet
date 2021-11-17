#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, char * argv[]) {
	FILE * fichier = fopen("DHM200.xyz", "r");
	}
	char ligne[100];
	while (fgets(ligne, 100, fichier) != NULL) {

      double valeur = atof(ligne);
	printf("%f",valeur);


	}
	fclose(fichier);
  return 0;
}


double * altitudes = malloc(37 * 44 * sizeof (double));

char * x = strchr(ligne, ' ');
if (x == NULL) return 0;
char * y = strchr(x + 1, ',');
if (y == NULL) return 0;
char * alt = strchr(y + 1, ',');
if (alt == NULL) return 0;
printf("%s\n", coordx);

for(int i = 0; i<longueur)

//Libérer le tableau
free(altitudes);

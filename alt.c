#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char * argv[]) {
  FILE*fichier = fopen("DHM200.xyz", 'r');
  if (file == NULL) {
		printf("Impossible d'ouvrir le fichier.\n");
		return 1;
	}



    return 0;
}

/*
double * altitudes = malloc(37 * 44 * sizeof (double));


FILE * fileToRead = fopen("DHM200.xyz", "r");
fread(altitudes, sizeof (double), 37 * 44, fileToRead);
fclose(fileToRead);


free(altitudes);
*/


/*
#include <stdio.h>
#include <stdlib.h>

int lireFichier(char * nomFichier, double * tableauARemplir, int longueur) {
    // Ouvrir le fichier
    FILE * file = fopen(nomFichier, "r");
    if (file == NULL) {
        fprintf(stderr, "Erreur: impossible d'ouvrir le fichier '%s'\n", nomFichier);
        exit(1);
    }

    // Lire ligne par ligne
    int n = 0;
    char buffer[100];
    while (fgets(buffer, 100, file) != NULL) {
        if (n >= longueur) break;
        tableauARemplir[n] = atof(buffer);
        n = n + 1;
    }

    // Fermer le fichier et renvoyer le nombre de lignes lues
    fclose(file);
    return n;
}

int main(int argc, char * argv[]) {
    double altitudes_tot[1465616];
    int longueur = lireFichier("DHM200.xyz", altitudes_tot, 1465616);

    // tremblement contient maintenant les valeurs du fichier "earthquake1"
    // (11000 cases total, longueurs cases utilisées, les autres cases sont non-initialisées)
    printf("%d\n", longueur);
    return 0;
}
*/

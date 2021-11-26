#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A. Structure
struct GpsPoint {
    double latitude;
    double longitude;
    float altitude;
};

// B. Afficher un point
void afficher(struct GpsPoint * point) {
    printf("%f %f %f\n", point->latitude, point->longitude, point->altitude);
}

// C. Lire une ligne
int lireLigne(char * ligne, struct GpsPoint * point) {
    char * espace1 = strchr(ligne, ' ');
    if (espace1 == NULL) return 0;
    char * espace2 = strchr(espace1 + 1, ' ');
    if (espace2 == NULL) return 0;

		double v1=atof(ligne);
		double v2=atof(espace1+1);
		double v3=atof(espace2+1);
		printf("%f,%f,%f\n", v1,v2,v3);
		if(v1 >= 592800.00 && v1 <= 600000.00 && v2 >= 095200.00 && v2 <= 103800.00){
				//Le compilateur ne comprend pas les deux conditions "<="
				//printf("%s\n","ok" );
			point->latitude = v1;
			point->longitude =v2;
			point->altitude = v3;
			printf("%f,%f,%f\n",v1,v2,v3);
		}
    return 1;
}

int lireFichier(char * nomFichier, struct GpsPoint * tableauARemplir, int longueur) {
    // Ouvrir le fichier
    FILE * file = fopen(nomFichier, "r");
    if (file == NULL) return -1;

    // Lire ligne par ligne
    int n = 0;
    char buffer[100];
    while (fgets(buffer, 100, file) != NULL) {
        if (n >= longueur) break;
        int ok = lireLigne(buffer, &tableauARemplir[n]);
        if (ok) n = n + 1;
    }
    fclose(file);
    return n;
}

int main(int argc, char * argv[]) {
    // D. Lire le fichier
    struct GpsPoint *points=malloc(100000);
    int nbPoints = lireFichier("DHM200.xyz", points, 100000);
    if (nbPoints == -1) {
        printf("Erreur: Le fichier n'existe pas ou n'est pas accessible.\n");
        return 1;
    } else if (nbPoints == 0) {
        printf("Erreur: Le fichier est vide ou pas dans le bon format.\n");
        return 1;
    }
    for (int i = 0; i < 10; i++) afficher(points + i);
		return 0;
	}

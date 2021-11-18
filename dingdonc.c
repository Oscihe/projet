#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// Structure
struct GpsPoint {
    double latitude;
    double longitude;
    float altitude;
};

// Lire une ligne et remplir la structure
int lireLigne(char * ligne, struct GpsPoint * point) {
    char * virgule1 = strchr(ligne, ' ');
    if (virgule1 == NULL) return 0;
    char * virgule2 = strchr(virgule1 + 1, ' ');
    if (virgule2 == NULL) return 0;
    double v1=atof(ligne);
    double v2=atof(virgule1+1);
    double v3=atof(virgule2+1);
    if(v1 >= 592800.00 && v1 <= 600000.00 && v2 >= 095200.00 && v2 <= 103800.00){
        point->latitude = v1;
        point->longitude = v2;
        point->altitude = v3;
        return 1;
    }
    return 0;
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
        if (ok) {
          n = n + 1;
        }
    }

    // Fermer le fichier et renvoyer le nombre de lignes lues
    fclose(file);
    return n;
}

bool writeCsv(char * filename, double * values, int sizeX, int sizeY) {
    FILE * file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "File %s not found.", filename);
        return false;
    }

    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            if (x > 0) fprintf(file, ", ");
            fprintf(file, "%f", values[y * sizeX + x]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return true;
}

int main(int argc, char * argv[]) {
    // Lire le fichier
    struct GpsPoint points[1628];
    int nbPoints = lireFichier("DHM200.xyz", points, 1628*sizeof(double));
    if (nbPoints == -1) {
        printf("Erreur: Le fichier n'existe pas ou n'est pas accessible.\n");
        return 1;
    } else if (nbPoints == 0) {
        printf("Erreur: Le fichier est vide ou pas dans le bon format.\n");
        return 1;
    }

	//Imprimer les valeurs x, y et les altitudes :
    //for (int i=0;i<nbPoints;i++){
      //printf("%f,%f,%f\n", points[i].altitude,points[i].longitude,points[i].latitude);
    //}

    //Pour ensuite créer un malloc contenant les altitudes:
    //x = latitude
    //y = longitude

    //x = x0 + 200*((37+i)%37)
    //y = y0 - 200*(i/37)
    //i = ((ymax - y)/200)*37 + ((x - xmin)/200)

    //Trouver xmin et ymax :

    //Initialiser xmin et ymax
    double xmin = points[0].latitude;
    double ymax = points[0].longitude;
    for(int i=1; i<nbPoints; i++){
		if(points[i].latitude<xmin){
			xmin=points[i].latitude;
		}
	}
	for(int i=1; i<nbPoints; i++){
		if(points[i].longitude>ymax){
			ymax=points[i].longitude;
		}
	}

	//Création du malloc contenant les altitudes :
	double * altitudes = malloc(1628*sizeof(double));
	for(int i=0; i<nbPoints; i++){

		altitudes[(((int) ymax- (int) points[i].longitude)/200)*37 + (((int) points[i].latitude- (int) xmin)/200)] = points[i].altitude;
	}

	writeCsv("altitudes.csv", altitudes, 37, 44);

	free(altitudes);

	//Imprimer les valeurs des altitudes se trouvant dans le malloc
	for(int i=0; i<nbPoints; i++){
		printf("%f, ", altitudes[i]);
	}

    return 0;
}

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

    //Pour ensuite cr??er un malloc contenant les altitudes:
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
<<<<<<< HEAD
  if(points[i].latitude<xmin){
   xmin=points[i].latitude;
  }
 }
 for(int i=1; i<nbPoints; i++){
  if(points[i].longitude>ymax){
   ymax=points[i].longitude;
  }
 }

 //Cr??ation du malloc contenant les altitudes :
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
=======
		if(points[i].latitude<xmin){
			xmin=points[i].latitude;
		}
	}
	for(int i=1; i<nbPoints; i++){
		if(points[i].longitude>ymax){
			ymax=points[i].longitude;
		}
	}

	//Cr??ation du malloc contenant les altitudes qui sont dans notre zone :
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
>>>>>>> ed5d1e6a9279487773e466f2c5aebfd256a019f6

  //Cr??ation d'un fichier csv contenant les coordonn??es du lac des Dix
  //Pour le faire, je cr??e d'abord un malloc contenant :
  //Une colonne avec les coordonn??es x
  //et une colonne avec les coordonn??es y
  /*
  double coord5x = 597000;
  double coord5y = 103200;
  double coord6x = 597600;
  double coord6y = 103200;
  double coord7x = 597000;
  double coord7y = 098000;
  double coord8x = 597600;
  double coord8y = 098000;
*/
/*
  double * lac = malloc(108*sizeof(double));
  ...

	writeCsv("lac_coord.csv", lac, 2, 54);

	free(lac);
*/
  /*
  //voir plus tard comment calculer les droites entre les angles du lac
  //D'abord faire tourner le programme juste avec un rectangle comme lac
  double coord1x = 597200;
  double coord1y = 098000;
  double coord2x = 598000;
  double coord2y = 098000;
  double coord3x = 596200;
  double coord3y = 101400;
  double coord4x = 597000;
  double coord4y = 101400;
  double coord5x = 597000;
  double coord5y = 103200;
  double coord6x = 597600;
  double coord6y = 103200;

  //Calcul des droites reliant les "angles" du lac
  //Droite 1 ?? 3
  double Dx13 = coord1x-coord3x;
  double Dy13 = coord3y-coord1y;
  double pente13 = Dy/Dx;
  */

  return 0;
}

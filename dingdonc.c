#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
#include <stdbool.h>
#include <time.h>

struct Gpspoint{
  double x;
  double y;
  float alt;
};
struct Gpspoint point[37*44];
=======
#include <math.h>


// Structure
struct GpsPoint {
    double latitude;
    double longitude;
    float altitude;
};
>>>>>>> 1114a8906dd57b19e6c9b7598d626e5a2d22231a

// Lire une ligne et remplir la structure
int lireLigne(char * ligne, struct GpsPoint * point) {
    char * virgule1 = strchr(ligne, ' ');
    if (virgule1 == NULL) return 0;
    char * virgule2 = strchr(virgule1 + 1, ' ');
    if (virgule2 == NULL) return 0;
<<<<<<< HEAD

    point->x = atof(ligne);
    point->y= atof(virgule1 + 1);
    point->alt = atof(virgule2 + 1);
    return 1;
=======
    double v1=atof(ligne);
    double v2=atof(virgule1+1);
    double v3=atof(virgule2+1);
    //printf("%f,%f,%f\n", v1,v2,v3);
    if(v1 >= 592800.00 && v1 <= 600000.00 && v2 >= 095200.00 && v2 <= 103800.00){
        //Le compilateur ne comprend pas les deux conditions "<="
        //printf("%s\n","ok" );
        point->latitude = v1;
        point->longitude = v2;
        point->altitude = v3;
        //printf("%f,%f,%f\n", point->longitude,point->latitude,point->altitude);
        //printf("%f\n",point->altitude );
        //printf("%f\n",point->alti );
        return 1;
    }
    return 0;
    //return 1;

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
          //printf("%f,%f,%f\n", tableauARemplir[n].altitude);
          //printf("%d\n",n);
        }
    }

    // Fermer le fichier et renvoyer le nombre de lignes lues
    fclose(file);
    return n;
>>>>>>> 1114a8906dd57b19e6c9b7598d626e5a2d22231a
}

int main(int argc, char * argv[]) {
<<<<<<< HEAD
  //double ymax=...;
  //double xmin=...;
  //double index=(ymax-y)/200*37+(x-xmin)/200;
  FILE * fichier = fopen("DHM200.xyz", 'r');
  char ligne[100];
//  double * altitudes = malloc(10000000 * sizeof (double));
  int i=0;
  while (fgets(ligne, 100, fichier) != NULL) {
    if(592800.00<=x<=600000.00 && 095200.00<=y<=103800.00){
      lireligne(ligne,&point);

    //printf("%d,%d,%d",x,y,z);

      //altitudes[index]=z;
    }
    i++;

    //altitudes[i]=atof(ok);
    //double valeur = atof(ligne);
  //  printf("%s",ligne);




  }
fclose(fichier);
=======
    // Lire le fichier
    struct GpsPoint points[1628];
    //struct GpsPoint * points = malloc(15000000*sizeof(struct GpsPoint));
    int nbPoints = lireFichier("DHM200.xyz", points, 1628*sizeof(double));
    if (nbPoints == -1) {
        printf("Erreur: Le fichier n'existe pas ou n'est pas accessible.\n");
        return 1;
    } else if (nbPoints == 0) {
        printf("Erreur: Le fichier est vide ou pas dans le bon format.\n");
        return 1;
    }
    //printf("%f",points[4].altitude);

    for (int i=0;i<nbPoints;i++){
      printf("%f,%f,%f\n", points[i].altitude,points[i].longitude,points[i].latitude);
    }
    return 0;
>>>>>>> 1114a8906dd57b19e6c9b7598d626e5a2d22231a
}

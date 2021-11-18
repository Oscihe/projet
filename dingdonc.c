#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


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
    //printf("%f,%f,%f\n", v1,v2,v3);
    if(v1 >= 592800.00 && v1 <= 600000.00 && v2 >= 095200.00 && v2 <= 103800.00){
        //Le compilateur ne comprend pas les deux conditions "<="
        //printf("%s\n","ok" );
        point->latitude = v1;
        point->longitude = v2;
        point->altitude = v3;
        printf("%f,%f,%f\n", point->longitude,point->latitude,point->altitude);
        //printf("%f\n",point->altitude );
        //printf("%f\n",point->alti );
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
        //printf("%f,%f,%f\n", tableauARemplir[n].altitude);
    }

    // Fermer le fichier et renvoyer le nombre de lignes lues
    fclose(file);
    return n;
}

int main(int argc, char * argv[]) {
    // Lire le fichier
    struct GpsPoint * points = malloc(15000000*sizeof(struct GpsPoint));
    int nbPoints = lireFichier("DHM200.xyz", points, 15000000*sizeof(double));
    if (nbPoints == -1) {
        printf("Erreur: Le fichier n'existe pas ou n'est pas accessible.\n");
        return 1;
    } else if (nbPoints == 0) {
        printf("Erreur: Le fichier est vide ou pas dans le bon format.\n");
        return 1;
    }


    //for (int i=0;i<nbPoints;i++){
      //printf("%f\n", points+i);

    return 0;
}

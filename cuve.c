#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
struct Grille {
	double lat;
	double longi;
	double pluie;
	double alt;
	int lac;
	int catch;
	double time;
};
int indexing(int x,int y){
  int i=(103800-y)/200*37+(x-592800)/200;
	return i;
}
void initialisation(double *malloc_hauteur,int compteur,double quantite_precip,double lac_lat_max,double lac_lat_min,double lac_long_min,double lac_long_max,struct Grille *grilles){
	//int lenxp=37;
	//int lenyp=44;
	//int total=lenxp*lenyp;
	for (int k=0;k<compteur;k++){
		grilles[compteur].longi=592800+200*((37+compteur)%37);
		grilles[compteur].lat=95200-200*(compteur/37);
		//ou bien est ce que c'est 103800-200*(compteur/37) ?!
		grilles[compteur].pluie=quantite_precip;
		grilles[compteur].alt=malloc_hauteur[compteur];
		//Tout entre dans le else et jamais dans le if (on le voit en mettant des "printf("ok");")...
		//mais de toute manière, le if et le else font la même chose (mettre pluie à 1)
		//et on a féjà mis les grilles[compteur].pluie=quantite_precip...
		if (grilles[compteur].longi<lac_long_max&&grilles[compteur].longi>lac_long_min&&lac_lat_max>grilles[compteur].lat&&lac_lat_min<grilles[compteur].lat){
			grilles[compteur].pluie=1;
			}
		else{
			grilles[compteur].pluie=1;
		}
	}
}
double  accumulation (int compteur1,struct Grille *grilles) {
	//int z=indexing(grilles[compteur1].long,grilles[compteur1].lat)
	int pos_x=grilles[compteur1].longi;
	int pos_y=grilles[compteur1].lat;;
	int y_min = 0;
	int x_min = 0;
	int h_min=0;
	while(grilles->longi!=592800||grilles->lat!=95200||grilles->longi!=600000||grilles->lat == 103800){
		for (int x= -200; x<7200; x=x+200){
			for (int y= -200; y<8600; y=y+200){
				//printf("ok");
				//ça a print le "ok" qu'une seule fois
				//est-ce que les "bornes" sont ok ?!
				//est-ce que c'est la bonne méthode ?!
				int i=indexing(pos_x+x,pos_y+y);
				if (h_min > grilles[i].alt){
					//printf("ok");
					//ça ne print pas le ok
					h_min = grilles[i].alt;
					y_min = grilles[i].lat;
					x_min = grilles[i].longi;
				}
			}
		}
		pos_x = x_min;
		pos_y = y_min;
		//printf("ok");
		//ça ne print pas le "ok"
	}
	if (grilles[indexing(x_min,y_min)].lac==1){
		grilles[compteur1].catch=1;
		printf("%d\n",grilles[compteur1].catch);
		//printf("ok");
		//ça ne print pas le "ok"
	}
	return 0;
}

struct Grille grilles[37*44];

int main(int argc, char * argv[]) {
	struct GpsPoint points[1628];
	int nbPoints = lireFichier("DHM200.xyz", points, 1628*sizeof(double));
	if (nbPoints == -1) {
			printf("Erreur: Le fichier n'existe pas ou n'est pas accessible.\n");
			return 1;
	} else if (nbPoints == 0) {
			printf("Erreur: Le fichier est vide ou pas dans le bon format.\n");
			return 1;
	}
	double xmin = points[0].latitude;
	double ymax = points[0].longitude;
	for(int i=1; i<nbPoints; i++){
		if(points[i].latitude<xmin){
		xmin=points[i].latitude;
		//printf("ok");
		//ça ne print pas le "ok"
		}
	}
	for(int i=1; i<nbPoints; i++){
			if(points[i].longitude>ymax){
				ymax=points[i].longitude;
				//printf("ok");
				//ça ne print pas le "ok"
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
	//for(int i=0; i<nbPoints; i++){
		//printf("%f, ", altitudes[i]);
	//}
	//int lenxp=37;
	//int lenyp=44;
	//int total=lenxp*lenyp;
	double quantite=0;
	//struct Grille grilles[total];
	//for (int l=0;l<total;l++){
	
	initialisation(altitudes,1628,1,103200,98000,597200,598000,grilles);
	
	for (int m=0;m<1628;m++){
		accumulation(m,grilles);
		if (grilles[m].catch==1){
			//printf("ok");
			//ça ne print pas le "ok"
			quantite=quantite+grilles[m].pluie;
			printf("%f",quantite);
		}
	}
	//printf("ok");
	//ça ne print pas le "ok"
	double volume_tot=quantite/1000*200;
	printf("Le volume totale d'eau est: %f",volume_tot);
	//printf("ok");
	//ça ne print pas le "ok"
	return 0;
}

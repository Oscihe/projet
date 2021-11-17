#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
struct Grille {
	double lat;
	double long;
	double pluie;
	double alt;
	int lac;
	int catch;
	double time;
};
int indexing(int x,int y){
  return y*37+x;
}
void initialisation(double malloc_hauteur,int compteur,double quantité_precip,double lac_lat_max,double lac_lat_min,double lac_long_min,double lac_long_max){
  int lenxp=37;
  int lenyp=44;
  int total=lenxp*lenyp;
  grilles[compteur].long=malloc[compteur];
  grilles[compteur].lat=malloc[compteur+1];
  grilles[compteur].pluie=quantité_precip;
  grilles[compteur].alt=malloc_hauteur[compteur+2];
  if (point.long<lac_long_max&&point.long>lac_long_min&&point.lat<lac_lat_max&&lac_lat_min<point.lat){
    point.lac=1;
  else{
    point.lac=0;
    }
  }
}
double  accumulation (int compteur1) {
  //int z=indexing(grilles[compteur1].long,grilles[compteur1].lat)
  int pos_x=grilles[compteur1].long;
  int pos_y=grilles[compteur1].lat;;
  int y_min = 0;
  int x_min = 0;
  int hmin=0;
	while (pos_x > -1 && pos_x <37 && pos_y > -1 && pos_y < 44) {
		for (int x= -1; i<2; i++){
			for (int y= -1; j<2; j++){
        int i=indexing(pos_x+x,pos_y+y);
				if (h_min > grilles[i].alt){
  					h_min = grilles[i].alt;
  					y_min = grilles[i].lat;
  					x_min = grilles[i].long;
        }
			}
		}
		pos_x = x_min;
		pos_y = y_min;
	}
  int u=indexing(x_min,y_min);
  if grilles[u].lac=1{
    grilles[compteur1].catch=1;
  }
	return 0;
}
int main(int argc, char * argv[]) {
	FILE * fichier = fopen("DHM200.xyz", "r");
	}
	char ligne[100];
	while (fgets(ligne, 100, fichier) != NULL) {
			double valeur = atof(ligne);
	printf("%f",valeur);
	}
	fclose(fichier);
  int lenxp=37;
  int lenyp=44;
  int total=lenxp*lenyp;
  double quantite=0;
  struct Grille grilles[total];
  for (int l=0;l<total;l++){
    initialisation(malloc_hauteur,l,1, struct Grille*,etc...)
  for (m=0;m<total;m++){
      if (grilles.catch[m]=1){
        quantité=quantité+grilles.pluie[m];
      }
    }
  }
  double volume_tot=quantité/1000*200;
  return 0;
}

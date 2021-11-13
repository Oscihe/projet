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
  Grilles[compteur].long=malloc[compteur];
  Grilles[compteur].lat=malloc[compteur+1];
  Grilles[compteur].pluie=quantité_precip;
  Grilles[compteur].alt=malloc_hauteur[compteur+3];
  if (point.long<lac_long_max&&point.long>lac_long_min&&point.lat<lac_lat_max&&lac_lat_min<point.lat){
    point.lac=1;
  else{
    point.lac=0;
    }
  }
}
double  accumulation (struct) {
  int z=indexing(x,y);
  int pos_x=x;
  int pos_y=y;
  int y_min = 0;
  int x_min = 0;
  int hmin=0;
	while (pos_x > -1 && pos_x <37 && pos_y > -1 && pos_y < 44) {
		for (int x= -1; i<2; i++){
			for (int y= -1; j<2; j++){
        int i=indexing(x,y);
				if (h_min > grilles[i].alt):
  					h_min = grilles[i].alt;
  					y_min = grilles[i].lat;
  					x_min = grilles[i].long;
        }
			}
		}
		pos_x = x_min;
		pos_y = y_min;
	}
  grilles[z].catch=grilles[i].pluie
	return 0;
}
int main(int argc, char * argv[]) {

  int lenxp=37;
  int lenyp=44;
  int total=lenxp*lenyp;
  double quantite=0;
  struct Grille grilles[total];
  for (int l=0;l<total;l++){
    initialisation(malloc_hauteur,l,1, struct Grille*,etc...)
  for (x=0;x<lenxp;x++){
    for (y=0;y<lenyp;y++){
      accumulation(x,y);
      int ti=indexing(x,y);
      if (grilles.catch[ti]=1){
        quantité=quantité+grilles.catch[ti];
      }
    }
  }
  double volume_tot=quantité/1000*200;
  return 0;
}

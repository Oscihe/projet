#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <curl/curl.h>

//commencer par ouvrir le fichier de données météo et ensuite
//les implémentés dans une structures Gps (coordonnées, altitude et précipitations)
//S'inspirer de l'exo terrain pour déterminer ou l'eau va se précipiter à l'aide de
//l'interpolation
struct Gps_point {
	double latitude;
	double longitude;
}

//changer l'angle de 0.01 degré décimale fait un changement de 1,11km.
//En prenant une boucle on incrémente de 0.0001 décimales, ce qui
//correspond à des cases de 11 mètres carrés environ.
//surface lac_dix=3.65km^2 profondeur_max=227 mètres. 400 millions de m^3 d'eau
//largeur_max=600m, longueur_max=5.3km
//formule L=2piRA/360 avec A la variation d'angle et L le déplacement désiré
;double a=360*10/(M_PI*2*6371); //0.089932 degré correspond à une zone approximative pour la longeur
//du lac+ses alentours en latitude car le lac est pratiquement parallèle aux
//latitudes. (9km)
double b=360*2/(M_PI*6371*2);//0.017986 (1.76km)

double latitude=4	;
double longitude=7.375611;
int main(int argc, char * argv[]) {
	for (int i=0; i<90;i++){
		longitude=7.375611;
		latitude=latitude+0.001;
		for (int j=0;j<18;j++){
			longitude=longitude+0.001;
			char site[1000];
			sprintf(site,"curl \"https://my.meteoblue.com/packages/basic-1h?apikey=8265088095b8&lat=%f&lon=%f&asl=453&tz=Europe%%2FZurich&city=Lausanne\" -o grimsel-eau",latitude,longitude);
			printf("%s\n",site);
			system(site);
		}
	}
return 0;
}

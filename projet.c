#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

double latitude=46.02036;
double longitude=7.375611;
for (	int i=0;i<900;i++){
	latitude=latitude+0.0001;
	for (int j=0;j<176;j++){
		longitude=longitude+0.0001;
		char site[100];
		site[0]="https://my.meteoblue.com/packages/basic-1h?apikey=8265088095b8&lat=";
		site[1]=latitude;
		site[2]="&lon=";
		site[3]=longitude;
		site[4]="&asl=453&tz=Europe%2FZurich&city=Lausanne";
		printf("%s\n",site)
int main(int argc, char * argv[]) {
    // Tableau avec les altitudes:  valeurs en x (largeur),
    //  valeurs en y (hauteur)
    double * altitudes = malloc( y* x * sizeof (double));

    // et les mettre dans le tableau "altitudes"
    FILE * fileToRead = fopen("", "r");
    fread(altitudes, sizeof (double), x*y, fileToRead);
    fclose(fileToRead);

    // A. Le point le plus bas et ses coordonnées
    double min = 0;
    int minX = 0;
    int minY = 0;
    for (int y = 0; y < 3601; y++) {
        for (int x = 0; x < 2501; x++) {
            int i = y * 2501 + x;
            if (altitudes[i] < min) {
                min= altitudes[i];
                minX = x;
                minY = y;
            else{
				t+=1;
				if (t==50){
					printf("Cuve trouvée en %d,%d.\n",x,y)
					//if cuve est assez proche des coordonnées du lac,
					//return la quantité de précipitations situées sur les 50
					//cases et les inclures dans le volume du lac.
            }
        }
         

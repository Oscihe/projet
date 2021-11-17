#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
int lireligne(char*ligne){
    char * virgule1 = strchr(ligne, ' ');
    if (virgule1 == NULL) return 0;
    char * virgule2 = strchr(virgule1 + 1, ' ');
    if (virgule2 == NULL) return 0;
    int x=atof(ligne);
    int y=atof(virgule1+1);
    int z=atof(virgule2+1);
    printf("%d,%d,%d",x,y,z);
    return 0;
}
int main(int argc, char * argv[]) {
  //double ymax=...;
  //double xmin=...;
  //double index=(ymax-y)/200*37+(x-xmin)/200;
  FILE * fichier = fopen("DHM200.xyz", "r");
  char ligne[100];
//  double * altitudes = malloc(10000000 * sizeof (double));
  int i=0;
  while (fgets(ligne, 100, fichier) != NULL) {
    lireligne(ligne);
    //printf("%d,%d,%d",x,y,z);
    //if(592800.00<=x<=600000.00&&095200.00<=y<=103800.00){
    //  altitudes[index]=z;
    //}
    i++;

    //altitudes[i]=atof(ok);
    //double valeur = atof(ligne);
  //  printf("%s",ligne);




  }
fclose(fichier);
}

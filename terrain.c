#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char * argv[]) {
    // Tableau avec les altitudes: 2501 valeurs en x (largeur),
    // 3601 valeurs en y (hauteur)
    double * altitudes = malloc(2501 * 3601 * sizeof (double));

    // Lire les données du fichier "mnt-suisse-romande"
    // et les mettre dans le tableau "altitudes"
    FILE * fileToRead = fopen("mnt-suisse-romande", "r");
    fread(altitudes, sizeof (double), 2501 * 3601, fileToRead);
    fclose(fileToRead);

    // L'altitude d'un point (x, y) se trouve dans la case
    // altitudes[y * 2501 + x]
    // Le code ci-dessus provient de l'exercice "Terrain"

    //la zone rectangulaire (autour du Lac des Dix) que l'on considère est entre ces coordonnées :
    //limite Nord-Ouest : 2'600'002.7, 1'095'486.2
    //Limite Nord-Est : 2'600'002.7, 1'095'298.2
    //Limite Sud-Est : 2'593'045.2, 1'095'298.2
    //Limite Sud-Ouest : 2'593'045.2, 1'095'486.2

    // Libérer le tableau
    free(altitudes);
    return 0;
}

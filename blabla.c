a#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
int main(int argc, char * argv[]) {
    for (int u=1;u<5;u++){
      FILE*fp;
      char str[20];
      sprintf(str,"%d",u);
      char* k=".csv";
      char*m=strcat(str,k);
      char prt[20];
      char* g="precipitation";
      sprintf(prt,"%s",g);
      char *b=strcat(prt,m);
      fp=fopen(b,"r");
    //for (int x=0;x<half;x++){
      //for (int l=0;l<value2;l++){
      char line[100];
      while(fgets(line,100,fp)!=NULL){
        printf("%s", line);
        double list[100];
        for(t=0;t<100;t++){
          list[t]=line[0];
        for(t)
        }
      }
    }
}
bool readCsv(char * filename, double * values, int sizeX, int sizeY) {
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "File %s not found.", filename);
        return false;
    }
    int y = 0;
    char buffer[10000];
    while (fgets(buffer, 10000, file) != NULL) {
        int x = 0;
        char * start = buffer;
        while (true) {
            values[y * sizeX + x] = atof(start);
            start = strchr(start, ',');
            if (start == NULL) break;
            start += 1;
            x += 1;
            if (x >= sizeX) break;
        }
        y += 1;
        if (y >= sizeY) break;
    }
    fclose(file);
    return true;
}
        //fread(creation,sizeof (double),1000,doc);

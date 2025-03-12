//  Sergi Palau Travé       NIU1750517
//  Nicolás Merayo Martos   NIU1752648 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nom[20];
    char estacio[35];
    int alt;
    float tmtj,tmxm,tmnm,tmx,tmn;
}MetCom;

void print_comarca(MetCom *comarca) {
    printf("%-20s ", comarca->nom);
    printf("%-35s ", comarca->estacio);
    printf("%-.1f ", comarca->tmx);
    printf("%-.1f", comarca->tmn);
    printf("\n");
}

void ex121(int numcom, MetCom *comarca, MetCom *comarca_max, MetCom *comarca_min, float *return_max, float *return_min) {
    // Exercici 1.2.1

    float mitjana_max = 0;
    float mitjana_min = 0;
    
    int index_min, index_max = 0;

    float max = comarca[0].tmx;
    float min = comarca[0].tmx;
    for (int i = 0; i < numcom; i++){
        mitjana_max = mitjana_max + comarca[i].tmx;
        mitjana_min = mitjana_min + comarca[i].tmn;
        if (comarca[i].tmx > max) {
            max = comarca[i].tmx;
            index_max = i;
        } 
        if (comarca[i].tmx < min) {
            min = comarca[i].tmn;
            index_min = i;
        } 
    }
    *return_max = mitjana_max/numcom;
    *return_min = mitjana_min/numcom;

    *comarca_max = comarca[index_max];
    *comarca_min = comarca[index_min];

}

int main(){
    FILE *meteo;
    MetCom *comarca;
    unsigned i=0,numcom=0,ll;

    
    if ((meteo=fopen("MeteoCat2023.txt","r"))==NULL){
        printf("No es pot obrir el fitxer\n");
        return 1;
    }
    
    while((ll=fgetc(meteo)) != EOF){
        if (ll=='\n'){numcom++;}
    }
    printf("\nDades de %d comarques\n",numcom);

    rewind(meteo);
    
    if((comarca = (MetCom *) malloc(numcom * sizeof(MetCom))) == NULL){
        printf ("\nNo es possible assignar la memoria necessaria...\n\n");
        return 1;
    }

    for(i=0;i<numcom;i++){
        fscanf(meteo, "%19[a-zA-Z'. -];", comarca[i].nom);
        fscanf(meteo, "%34[a-zA-Z'. -];", comarca[i].estacio);
        fscanf(meteo, "%d;", &comarca[i].alt);
        fscanf(meteo, "%f;", &(comarca[i].tmtj));
        fscanf(meteo, "%f;", &(comarca[i].tmxm));
        fscanf(meteo, "%f;", &(comarca[i].tmnm));
        fscanf(meteo, "%f;", &(comarca[i].tmx));
        fscanf(meteo, "%f\n", &(comarca[i].tmn));
 
    }
    

    printf("Fi de la lectura.....\n\n");
    
    fclose(meteo);

    printf("   Comarca              Estacio                             Max\n");
    printf("================================================================\n");
    for(i=0;i<numcom;i++){
        printf("%2u ",i+1);
        printf("%-20s ",comarca[i].nom);
        printf("%-35s ",comarca[i].estacio);
        printf("%-.1f",comarca[i].tmx);
        printf("\n");
    }

    MetCom comarca_max, comarca_min;
    float mitjana_max, mitjana_min; 
    ex121(numcom, comarca, &comarca_max, &comarca_min, &mitjana_max, &mitjana_min);

    printf("\nLa mitjana de temperatures maximes es %f\n", mitjana_max);
    printf("La mitjana de temperatures minimes es %f\n", mitjana_min);

    printf("\nComarca amb la temperatura maxima: \n");
    print_comarca(&comarca_max);
    printf("Comarca amb la temperatura minima: \n");

    print_comarca(&comarca_min);

    return 0;
}

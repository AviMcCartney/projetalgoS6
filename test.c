#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool chainage_arriere(char *But,char *base_regles){

    bool resultat = false;
    char *reglecomplete;
    char *c;
    char *ptr;
    char *conclusion;
    char *temp;

    FILE *regle=fopen(base_regles,"r");

    if (base_regles != NULL){
        puts("CHEH");
        fclose(regle);
    } 
    do {
        c = fgetc(regle);
        strcat(reglecomplete,c);
    }while (c!=";");

    while (base_regles != NULL && resultat==false){
        do {
            temp=">";
            ptr = strchr(reglecomplete,temp);
            conclusion = reglecomplete+ (int)ptr +2;
        }while (c!=";");
    }
    printf("%s",conclusion);
    return true;
}



int main(){
    char *But;
    scanf("%s\n",But);
    chainage_arriere(But,"test.kbs");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
    int nb = -1;
    printf("\n(0) Quitter\n");
    printf("(1) Chainage avant\n");
    printf("(2) Chainage arrière\n");
    printf("Votre choix: ");
    scanf("%d", &nb);
    printf("\n");
    return nb;
}
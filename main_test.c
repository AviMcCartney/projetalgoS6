// #include "chainage_avant.c"

// int main() {
//     // Chainage arrière
//     printf("Chainage arrière: \n\n");
//     char but[LEN];
//     char resultatFait[LEN * 10] = "";

//     printf("Entrez le but: ");
    
//     fgets(but, LEN, stdin);
//     but[strcspn(but, "\n")] = '\0';

//     AjouterRegle("b d e", "f", 1);
//     AjouterRegle("g d", "a", 2);
//     AjouterRegle("f c", "a", 3);
//     AjouterRegle("b", "x", 4);
//     AjouterRegle("e", "d", 5);
//     AjouterRegle("a x", "h", 6);
//     AjouterRegle("c", "d", 7);
//     AjouterRegle("x c", "a", 8);
//     AjouterRegle("x b", "d", 9);

//     AjouterFait("b", 0); 
//     AjouterFait("c", 0);

//     if (MoteurInference(but, resultatFait)) {
//         printf("%s est vrai.\n", but);
//         printf("Fait ajouté: %s\n", resultatFait);
//     } else
//         printf("%s n'est pas prouvé.\n", but);
    
//     // Chainage arrière
//     printf("\nChainage avant: \n\n");
//     CreerFaits_av("b", 0);
//     CreerFaits_av("c", 0);

//     MoteurInference_av();
//     AfficheFaits();
    
//     freeRegles();
//     freeFaits();

//     return 0;
// }

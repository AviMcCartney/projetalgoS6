#include "struct_chainageV2.h"
#include "lectureV2.h" // Inclure le fichier pour la lecture des règles depuis le fichier KBS
#include "chainage_avantV2.h" // Inclure le fichier d'en-tête pour les déclarations de fonctions
#include "structure.h"


void MoteurInference_av() {
    int ajoute = 1;

    while (ajoute) {
        ajoute = 0;
        Regles *RegleCourante = liste_de_regles;
        while (RegleCourante != NULL) {
            int antecedentMatch = 1;
            char *antecedentToken = strtok(RegleCourante->antecedent, " ");
            while (antecedentToken != NULL) {
                Fait *FaitCourant = liste_de_faits;
                int trouve = 0;
                while (FaitCourant != NULL) {
                    if (strcmp(antecedentToken, FaitCourant->fait) == 0) {
                        trouve = 1;
                        break;
                    }
                    FaitCourant = FaitCourant->suiv;
                }
                if (!trouve) {
                    antecedentMatch = 0;
                    break;
                }
                antecedentToken = strtok(NULL, " ");
            }
            if (antecedentMatch) {
                char *consequentToken = strtok(RegleCourante->consequent, " ");
                while (consequentToken != NULL) {
                    Fait *FaitCourant = liste_de_faits;
                    int trouve = 0;
                    while (FaitCourant != NULL) {
                        if (strcmp(consequentToken, FaitCourant->fait) == 0) {
                            trouve = 1;
                            break;
                        }
                        FaitCourant = FaitCourant->suiv;
                    }
                    if (!trouve) {
                        AjouterFait(consequentToken, RegleCourante->nb_regles);
                        ajoute = 1;
                    }
                    consequentToken = strtok(NULL, " ");
                }
            }
            RegleCourante = RegleCourante->suiv;
        }
    }
}

void AfficheFaits() {
    printf("Fait ajouté:\n");
    Fait *FaitCourant = liste_de_faits;
    Fait **FaitArray = (Fait**)malloc(sizeof(Fait*) * 100);
    int index = 0;

    while (FaitCourant != NULL) {
        if (FaitCourant->nb_regles != 0) {
            FaitArray[index++] = FaitCourant;
        }
        FaitCourant = FaitCourant->suiv;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("R%d %s\n", FaitArray[i]->nb_regles, FaitArray[i]->fait);
    }

    free(FaitArray);
}

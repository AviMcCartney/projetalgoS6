#include "struct_chainageV2.h"
#include "lectureV2.h" // Inclure le fichier pour la lecture des règles depuis le fichier KBS
#include "chainage_arriereV2.h" // Inclure le fichier d'en-tête pour les déclarations de fonctions
#include "structure.h"


int MoteurInference_ar(char *but, char *resultatFait) {
    int resultat = 0;
    Fait *FaitCourant = liste_de_faits;

    while (FaitCourant != NULL) {
        if (strcmp(but, FaitCourant->fait) == 0)
            return 1;
        FaitCourant = FaitCourant->suiv;
    }

    Regles *RegleCourante = liste_de_regles;
    while (RegleCourante != NULL) {
        if (strcmp(but, RegleCourante->consequent) == 0) {
            int hypothese = 1;
            char *token = strtok(RegleCourante->antecedent, " ");
            while (token != NULL) {
                int trouve = 0;
                FaitCourant = liste_de_faits;
                while (FaitCourant != NULL) {
                    if (strcmp(token, FaitCourant->fait) == 0) {
                        trouve = 1;
                        break;
                    }
                    FaitCourant = FaitCourant->suiv;
                }
                if (!trouve) {
                    hypothese = MoteurInference_ar(token, resultatFait);
                    if (!hypothese)
                        break;
                }
                token = strtok(NULL, " ");
            }
            if (hypothese) {
                AjouterFait(but, RegleCourante->nb_regles);
                if (strlen(resultatFait) > 0)
                    strcat(resultatFait, " > ");
                strcat(resultatFait, "R");
                char regleStrNb[10];
                sprintf(regleStrNb, "%d", RegleCourante->nb_regles);
                strcat(resultatFait, regleStrNb);
                strcat(resultatFait, "-");
                strcat(resultatFait, but);
                resultat = 1;
                break;
            }
        }
        RegleCourante = RegleCourante->suiv;
    }
    return resultat;
}

void freeRegles() {
    Regles *regles;
    while (liste_de_regles != NULL) {
        regles = liste_de_regles;
        liste_de_regles = liste_de_regles->suiv;
        free(regles);
    }
}

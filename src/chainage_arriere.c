#include "struct_chainage.h"


Regles *liste_de_regles = NULL; // initialisation de la liste de règles
Fait *liste_de_faits = NULL; // initialisation de la liste de faits

Regles *CreerRegles(char *antecedent, char *consequent, int nb_regles) {
    /*
    Fonction de création de règles
    */
    Regles *regle = (Regles *)malloc(sizeof(Regles));
    if (regle == NULL) {
        printf("Échec de l'allocation mémoire !\n");
        exit(1);
    }
    strcpy(regle->antecedent, antecedent); // copie la chaîne de caractères des antécédents dans la structure de règle
    strcpy(regle->consequent, consequent); // copie la chaîne de caractères des conséquences dans la structure de règle
    regle->nb_regles = nb_regles; // affecte le nombre de règles à la structure de règle
    regle->suiv = NULL;
    return regle;
}

Fait *CreerFaits(char *fact, int nb_regles) {
    /*
    Fonction de création de faits
    */
    Fait *un_fait = (Fait *)malloc(sizeof(Fait));
    if (un_fait == NULL) {
        printf("Échec de l'allocation mémoire !\n");
        exit(1);
    }
    strcpy(un_fait->fait, fact); // copie la chaîne de caractères représentant le fait dans la structure de fait
    un_fait->nb_regles = nb_regles; // affecte le nombre de règles associées au fait dans la structure de fait
    un_fait->suiv = NULL;
    return un_fait;
}

void AjouterRegle(char *antecedent, char *consequent, int nb_regles) {
    /*
    Fonction qui ajoute un règle dans la liste de règles
    */
    Regles *regle = CreerRegles(antecedent, consequent, nb_regles); // créer une nouvelle règle avec les paramètres spécifiés
    regle->suiv = liste_de_regles;
    liste_de_regles = regle; // met à jour la tête de la liste de règles vers la nouvelle règle
}

void AjouterFait(char *fact, int nb_regles) {
    /*
    Fonction qui ajoute un fait dans la liste de faits
    */
    Fait *fait = CreerFaits(fact, nb_regles); // créer un nouveau fait avec le nom de fait et le nombre de règles spécifiés
    fait->suiv = liste_de_faits;
    liste_de_faits = fait; // met à jour la tête de la liste de faits pour pointer vers le nouveau fait
}

int MoteurInference(char *but, char *resultatFait) {
    /*
    Fonction qui retourne si le but est atteint ou non
    */
    int i, j;
    int resultat = 0;
    Fait *FaitCourant = liste_de_faits;

    while (FaitCourant != NULL) {
        if (strcmp(but, FaitCourant->fait) == 0) // vérifie si le nom du fait actuel correspond au but
            return 1;
        FaitCourant = FaitCourant->suiv;
    }

    Regles *RegleCourante = liste_de_regles;
    while (RegleCourante != NULL) {
        if (strcmp(but, RegleCourante->consequent) == 0) { // vérifie si la conséquence de la règle courante correspond au but
            int hypothese = 1;
            char *token = strtok(RegleCourante->antecedent, " "); // initialise un token pour parcourir les antécédents de la règle courante
            while (token != NULL) { // tant qu'il n'est pas null on continue
                int trouve = 0;
                FaitCourant = liste_de_faits; // initialisation de la liste de faits
                while (FaitCourant != NULL) { // tant que celle ci n'est pas vide on continue
                    if (strcmp(token, FaitCourant->fait) == 0) { // vérifie si le fait courant correspond à l'antécédent actuel
                        trouve = 1;
                        break;
                    }
                    FaitCourant = FaitCourant->suiv;
                }
                if (!trouve) {
                    hypothese = MoteurInference(token, resultatFait); // vérifie si le fait est déductible, en fournissant le fait comme but
                    if (!hypothese)
                        break;
                }
                token = strtok(NULL, " "); // passe au token suivant
            }
            if (hypothese) { // vérifie si nos hypothèse sont vérifiées
                AjouterFait(but, RegleCourante->nb_regles); // ajoute le fait recherché à la base de faits
                if (strlen(resultatFait) > 0)
                    strcat(resultatFait, " > "); // affichage
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
    /*
    Fonction de libération de mémoire
    */
    Regles *regles;
    while (liste_de_regles != NULL) {
        regles = liste_de_regles;
        liste_de_regles = liste_de_regles->suiv;
        free(regles);
    }
}

void freeFaits() {
    /*
    Fonction de libération de mémoire
    */
    Fait *faits;
    while (liste_de_faits != NULL) {
        faits = liste_de_faits;
        liste_de_faits = liste_de_faits->suiv;
        free(faits);
    }
}
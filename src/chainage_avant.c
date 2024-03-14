#include "chainage_arriere.c"

void CreerRegles_av(char* antecedent, char* consequent, int nb_regles) {
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
    regle->suiv = liste_de_regles; 
    liste_de_regles = regle; // met à jour la tête de la liste de règles vers la nouvelle règle
}

void CreerFaits_av(char* fact, int nb_regles) {
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
    un_fait->suiv = liste_de_faits;
    liste_de_faits = un_fait; // met à jour la tête de la liste de faits vers le nouveau fait
}

void MoteurInference_av() {
    /*
    Fonction qui retourne un chemin
    */
    int ajoute = 1; // permet de rester dans la boucle tant qu'un fait est ajouté

    while (ajoute) {
        ajoute = 0;
        Regles *RegleCourante = liste_de_regles; // initialisation de la liste de regle
        while (RegleCourante != NULL) {
            int antecedentMatch = 1;
            char *antecedentToken = strtok(RegleCourante->antecedent, " "); // délimitation par les espaces
            while (antecedentToken != NULL) { // tant qu'on a un antécédent on continue
                Fait *FaitCourant = liste_de_faits; // initialisation des faits
                int trouve = 0;
                while (FaitCourant != NULL) { // tant qu'on a des faits on continue
                    if (strcmp(antecedentToken, FaitCourant->fait) == 0) { // vérifie si le token extrait de l'antécédent d'une règle est égal au fait courant de la base de faits
                        trouve = 1;
                        break;
                    }
                    FaitCourant = FaitCourant->suiv;
                }
                if (!trouve) { // si on ne trouve pas on arrête
                    antecedentMatch = 0;
                    break;
                }
                antecedentToken = strtok(NULL, " "); // extrait le prochain token de l'antécédent de la règle courante
            }
            if (antecedentMatch) {
                char *consequentToken = strtok(RegleCourante->consequent, " ");
                while (consequentToken != NULL) {
                    Fait *FaitCourant = liste_de_faits;
                    int trouve = 0;
                    while (FaitCourant != NULL) { // tant qu'on a des faits à traiter on continue
                        if (strcmp(consequentToken, FaitCourant->fait) == 0) { // vérifie si la conséquence actuelle est égale à un fait existant dans la base de faits 
                            trouve = 1;
                            break;
                        }
                        FaitCourant = FaitCourant->suiv;
                    }
                    if (!trouve) {
                        CreerFaits_av(consequentToken, RegleCourante->nb_regles); // création d'un nouveau fait dans la base de faits avec la conséquence actuelle
                        ajoute = 1;
                    }
                    consequentToken = strtok(NULL, " "); // passe à la prochaine conséquence de la règle courante
                }
            }
            RegleCourante = RegleCourante->suiv; // passe à la règle suivante dans la liste de règles
        }
    }
}

void AfficheFaits() {
    /*
    Fonction d'affichage des faits
    */
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

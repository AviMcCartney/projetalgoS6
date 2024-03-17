/**
 * @file fait.h
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier d'en-tête pour les fonctions de manipulation des faits.
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef FAIT_H
#define FAIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Structure pour représenter un fait.
 *
 * Cette structure contient un identifiant pour le fait, le nombre de faits et un pointeur vers le fait suivant dans la liste.
 */
typedef struct Faits
{
    int nombre_faits;
    char *identifiant;
    struct Faits *suiv;
} Faits;

/**
 * @brief Crée un nouveau fait.
 *
 * @return Faits* Retourne un pointeur vers le nouveau fait créé.
 */
Faits *CreerFaits();

/**
 * @brief Insère un fait dans une liste de faits.
 *
 * @param tete Un pointeur vers le premier élément de la liste de faits.
 * @param f Un pointeur vers le fait à insérer.
 * @return Faits* Retourne un pointeur vers le premier élément de la liste de faits mise à jour.
 */
Faits *InsererFaits(Faits *tete, Faits *f);

/**
 * @brief Ajoute des faits à une liste de faits.
 *
 * @return Faits* Retourne un pointeur vers le premier élément de la liste de faits mise à jour.
 */
Faits *AjouterFaits();

/**
 * @brief Ajoute un fait à la suite d'une liste de faits.
 *
 * @param liste Un pointeur vers le premier élément de la liste de faits.
 * @param nouveauFait Une chaîne de caractères représentant l'identifiant du nouveau fait à ajouter.
 * @return Faits* Retourne un pointeur vers le premier élément de la liste de faits mise à jour.
 */
Faits *AjouterFaitsSuite(Faits *liste, const char *nouveauFait);

/**
 * @brief Affiche une liste de faits.
 *
 * @param tete Un pointeur vers le premier élément de la liste de faits.
 */
void AfficherFaits(Faits *tete);

/**
 * @brief Libère la mémoire allouée à une liste de faits.
 *
 * @param tete Un pointeur vers le premier élément de la liste de faits.
 */
void LibererFaits(Faits *tete);

/**
 * @brief Vérifie si un fait est présent dans une liste de faits.
 *
 * @param liste_faits Un pointeur vers le premier élément de la liste de faits.
 * @param but Une chaîne de caractères représentant le fait à rechercher.
 * @return int Retourne 1 si le fait est trouvé dans la liste, sinon retourne 0.
 */
int FaitPresent(Faits *liste_faits, const char *but);

#endif // FAIT_H

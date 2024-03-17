/**
 * @file fait.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier fait.c contenant l'ensemble des procédures pour la gestion des faits.
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fait.h"
#include "memoire.h"

/**
 * @brief Crée un nouveau fait.
 *
 * Cette fonction alloue de la mémoire pour un nouveau fait et initialise ses membres.
 *
 * @return Faits* Retourne un pointeur vers le nouveau fait créé.
 */
Faits *CreerFaits()
{
    Faits *nouveau = allouer_malloc(sizeof(Faits));
    nouveau->nombre_faits = 0;
    nouveau->identifiant = NULL;
    nouveau->suiv = NULL;
    return nouveau;
}

/**
 * @brief Insère un fait dans une liste de faits.
 *
 * Cette fonction insère un fait à la fin d'une liste de faits.
 *
 * @param tete Un pointeur vers le premier élément de la liste de faits.
 * @param f Un pointeur vers le fait à insérer.
 * @return Faits* Retourne un pointeur vers le premier élément de la liste de faits mise à jour.
 */
Faits *InsererFaits(Faits *tete, Faits *f)
{
    if (tete == NULL)
        return f;
    else
        tete->suiv = InsererFaits(tete->suiv, f);
    return tete;
}

/**
 * @brief Ajoute des faits à une liste de faits.
 *
 * Cette fonction demande à l'utilisateur combien de faits il souhaite ajouter, puis ajoute ces faits à la liste.
 *
 * @return Faits* Retourne un pointeur vers le premier élément de la liste de faits mise à jour.
 */
Faits *AjouterFaits()
{
    Faits *liste = NULL;
    int nombre_faits;
    printf("Combien de faits voulez-vous ajouter ? ");
    scanf("%d", &nombre_faits);
    for (int i = 0; i < nombre_faits; i++)
    {
        char identifiant[100];
        printf("Saisir un fait: ");
        scanf("%s", identifiant);
        Faits *nouveau = CreerFaits();
        nouveau->identifiant = strdup(identifiant);
        liste = InsererFaits(liste, nouveau);
    }
    return liste;
}

/**
 * @brief Ajoute un fait à la suite d'une liste de faits.
 *
 * Cette fonction crée un nouveau fait avec l'identifiant spécifié et l'insère à la fin de la liste de faits donnée.
 *
 * @param liste Un pointeur vers le premier élément de la liste de faits.
 * @param nouveauFait Une chaîne de caractères représentant l'identifiant du nouveau fait à ajouter.
 * @return Faits* Retourne un pointeur vers le premier élément de la liste de faits mise à jour.
 */
Faits *AjouterFaitsSuite(Faits *liste, const char *nouveauFait)
{
    Faits *nouveau = CreerFaits();
    nouveau->identifiant = strdup(nouveauFait);
    return InsererFaits(liste, nouveau);
}

/**
 * @brief Affiche une liste de faits.
 *
 * Cette fonction parcourt une liste de faits et affiche l'identifiant de chaque fait.
 *
 * @param tete Un pointeur vers le premier élément de la liste de faits.
 */
void AfficherFaits(Faits *tete)
{
    Faits *courant = tete;
    while (courant != NULL)
    {
        printf("%s -> ", courant->identifiant);
        courant = courant->suiv;
    }
    printf("NULL\n");
}

/**
 * @brief Libère la mémoire allouée à une liste de faits.
 *
 * Cette fonction parcourt une liste de faits et libère la mémoire allouée à chaque fait et à son identifiant.
 *
 * @param tete Un pointeur vers le premier élément de la liste de faits.
 */
void LibererFaits(Faits *tete)
{
    Faits *courant = tete;
    while (courant != NULL)
    {
        Faits *suivant = courant->suiv;
        free(courant->identifiant);
        free(courant);
        courant = suivant;
    }
}

int FaitPresent(Faits *liste_faits, const char *but)
{
    Faits *courant = liste_faits;
    while (courant != NULL)
    {
        if (strcmp(courant->identifiant, but) == 0)
        {
            return 1;
        }
        courant = courant->suiv;
    }
    return 0;
}
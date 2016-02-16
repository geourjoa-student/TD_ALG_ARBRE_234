/*
 * arbre234.h
 *
 *  Created on: Feb 9, 2016
 *      Author: anthony
 */

#ifndef ARBRE234_H_
#define ARBRE234_H_

// Défintion des constantes

#define NB_MAX_CLES 3
#define NB_MAX_FILS 4

#define true 1
#define false 0

/* Définition de type */

typedef int bool;

typedef struct Int_list Int_list;
typedef struct Arbre_list Arbre_list;

typedef struct Arbre Arbre;
struct Arbre {
	int cles[NB_MAX_CLES];
	Arbre* fils[NB_MAX_FILS];
	int nbCles;
	int nbFils;

};

/* Méthodes */

// La fonction n'est pas correct, certaines insertions échouent ou provoque des pertes de données.
Arbre* insererDansArbre(Arbre *a, int cle);

/* false : la clé n'est pas présente
 * true : la clé est présente
 * Cette fonction de recherche est très simpliste et ne tire pas partie des propriétés des arbres 2-4.
 */
bool recherche(Arbre *a, int cle);

/*
 * Cette fonction de recherche se veut plus intelligente en ne parcourant pas des sous-arbres inutilement.
 */
bool recherche2(Arbre *a, int cle);

#endif /* ARBRE234_H_ */

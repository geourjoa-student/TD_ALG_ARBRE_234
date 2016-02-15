/*
 * arbre234.h
 *
 *  Created on: Feb 9, 2016
 *      Author: anthony
 */

#ifndef ARBRE234_H_
#define ARBRE234_H_


/* Définition de type */
#define NB_MAX_CLES 3
#define NB_MAX_FILS 4

typedef int bool;
#define true 1
#define false 0



typedef struct Int_list Int_list;
typedef struct Arbre_list Arbre_list;

typedef struct Arbre Arbre;
struct Arbre
{
    int cles[NB_MAX_CLES];
    Arbre* fils[NB_MAX_FILS];
    int nbCles;
    int nbFils;

};






/* Méthodes */

Arbre* creerArbre ( int cle_racine);

Arbre* insererDansArbre ( Arbre *a, int cle_);

int nbCles(Arbre *a);


/* 0 : la clé n'est pas présente
 * !=0 : la clé est présente
 * Cette fonction de recherche est très simpliste et ne tire pas partie des propriétés des arbres 2-4.
 */
bool recherche ( Arbre *a, int cle );

/*
 * Cette fonction de recherche se veut plus intélligente en ne parcourant par des sous-arbres inutilement
 */
//bool recherche2 ( Arbre *a, int cle );

#endif /* ARBRE234_H_ */

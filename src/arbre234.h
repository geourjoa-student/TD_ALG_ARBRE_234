/*
 * arbre234.h
 *
 *  Created on: Feb 9, 2016
 *      Author: anthony
 */

#ifndef ARBRE234_H_
#define ARBRE234_H_


/* Définition de type */
typedef int bool;
#define true 1
#define false 0

typedef struct Int_list Int_list;
typedef struct Arbre_list Arbre_list;

typedef struct Arbre Arbre;
struct Arbre
{
    Int_list *cles;
    Arbre_list *fils;
};


struct Int_list {
	int cle;
	Int_list *suivant;
};


struct Arbre_list {
	Arbre a;
	Arbre_list *suivant;
};




/* Méthodes */

Arbre* creerArbre ( int cle_racine);

Arbre* insererDansArbre ( Arbre *a, int cle_);




/* 0 : la clé n'est pas présente
 * !=0 : la clé est présente
 * Cette fonction de recherche est très simpliste et ne tire pas partie des propriétés des arbres 2-4.
 */
bool recherche ( Arbre *a, int cle );

/*
 * Cette fonction de recherche se veut plus intélligente en ne parcourant par des sous-arbres inutilement
 */
bool recherche2 ( Arbre *a, int cle );

#endif /* ARBRE234_H_ */

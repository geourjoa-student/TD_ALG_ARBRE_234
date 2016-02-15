/*
 * arbre234.c
 *
 *  Created on: Feb 9, 2016
 *      Author: anthony
 */

#include <stdio.h>
#include <stdlib.h>
#include "arbre234.h"

Arbre* creerArbre(int cle_racine) {
	Arbre *a = (Arbre *) malloc(sizeof(Arbre));

	a->cles = (Int_list *) malloc(sizeof(Int_list));
	a->cles->cle = cle_racine;
	a->cles->suivant = NULL;

	a->fils = NULL;

	return a;
}

bool recherche(Arbre *a, int cle) {

	Arbre_list *courant;

	if (a == NULL)
		return false;

	if (estPresentDansLesCles(a->cles, cle))
		return true;

	courant = a->fils;
	while (courant != NULL && !recherche(&(courant->a), cle)) {
		courant = courant->suivant;
	}

	return (courant != NULL);

}

bool recherche2(Arbre *a, int cle) {

	Arbre_list *filsCourant;
	Int_list *cleCourante;

	int place = 0;
	int i;

	if (a == NULL)
		return false;

	if (estPresentDansLesCles(a->cles, cle))
		return true;

	if (a->fils == NULL)
		return false;

	cleCourante = a->cles;

	while (cleCourante != NULL && cleCourante->cle <= cle) {
		cleCourante = cleCourante->suivant;
		place++;
	}

	filsCourant = a->fils;

	for (i = 0; i < place; ++i) {
		filsCourant = filsCourant->suivant;
	}

	return recherche2(&filsCourant->a, cle);

}

bool estPresentDansLesCles(Int_list *l, int cle) {
	Int_list *courant = l;
	while (courant != NULL && courant->cle != cle) {
		courant = courant->suivant;
	}

	return (courant != NULL);
}

int nbCles(Arbre *a) {
	int nbCles = 0;

	Int_list *courant = a->cles;
	while (courant != NULL) {
		courant = courant->suivant;
		nbCles++;
	}

	return nbCles;
}

Arbre* insererDansArbre(Arbre *a, int cle) {

	Arbre *pere;

	if (a == NULL) {
		a = (Arbre *) malloc(sizeof(Arbre));

		a->cles->cle;
		a->cles->suivant = NULL;

		a->fils = NULL;
	} else {
		if (nbCles( a ) == 3) {
			pere = (Arbre *) malloc(sizeof(Arbre));
			pere->fils->a=*a;
			a=pere;
		}

		a=insertionDansArbreRec( a, cle);

	}

	return a;

}

Arbre* insertionDansArbreRec( Arbre *a, int cle ) {

	int i = 1;

	while ( i <= nbCles(a) && (cle > ))

}







































































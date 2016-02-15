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

bool estPresentDansLesCles(Int_list *l, int cle) {
	Int_list *courant = l;
	while (courant != NULL && courant->cle != cle) {
		courant = courant->suivant;
	}

	return (courant != NULL);
}


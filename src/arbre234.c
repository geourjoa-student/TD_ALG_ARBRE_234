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

	a->cles[0] = cle_racine;
	a->cles[1] = NULL;
	a->cles[2] = NULL;

	a->nbCles = 1;

	a->nbFils = 0;

	int i;
	for (i = 0; i < NB_MAX_FILS; ++i) {
		a->fils[i] = NULL;
	}

	return a;
}

bool estPresentDansLesCles(int cles[], int nbCles, int cle) {

	int i;
	for (i = 0; i < nbCles; ++i) {
		if (cles[i] == cle) {
			return true;
		}
	}

	return false;

}

bool recherche(Arbre *a, int cle) {

	if (a == NULL)
		return false;

	if (estPresentDansLesCles(a->cles, a->nbCles, cle))
		return true;

	int i;
	for (i = 0; i < a->nbFils; ++i) {
		if (recherche(a->fils[i], cle))
			return true;
	}

	return false;
}

bool recherche2(Arbre *a, int cle) {

	int i = 0;

	if (a == NULL)
		return false;

	if (estPresentDansLesCles(a->cles, a->nbCles, cle))
		return true;

	if (a->fils == NULL)
		return false;

	while (i < a->nbCles && cle < a->cles[i]) {
		i++;
	}

	return recherche2(a->fils[i], cle);

}


/*
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





 */


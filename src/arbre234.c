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


Arbre* eclatement(Arbre *a, int i){

	int j;

	Arbre *t = (Arbre *) malloc(sizeof(Arbre));

	t->cles[0]=a->fils[i]->cles[3];
	t->cles[1]=NULL;
	t->cles[2]=NULL;


	t->fils[0]=a->fils[i]->fils[3];
	t->fils[1]=a->fils[i]->fils[4];
	t->fils[2]=NULL;
	t->fils[3]=NULL;

	t->nbCles=1;
	t->nbFils=2;

	a->fils[i+1]=t;

	a->fils[i]->nbCles=1;

	// TODO Attention indice
	for (j = a->nbCles; j < i; ++j) {
		a->cles[i]=a->cles[i-1];
		a->fils[j+1]=a->fils[i];
	}

	a->cles[i]=a->fils[i]->cles[1];
	a->nbCles++;


	return a;
}


Arbre* insertionDansArbreRec(Arbre *a, int cle) {

	int i = 0;
	int j;

	while ( (i < a->nbCles) && (cle > a->cles[i]) ){
		i++;
	}

	if ( !((i<=a->nbCles) && (cle == a->cles[i]))) {
		if (a->fils[0]==NULL) {
			for (j = a->nbCles-1; j >= i; --j){ // TODO Pas sûr du -1
				a->cles[j+1]=a->cles[i];
			}

			a->nbCles++;

			// TODO Inutile ?
			//a->fils[3] = NULL;

			a->cles[i]=cle;

		}
		else {
			if(a->fils[i]->nbCles==3){
				a=eclatement(a,i);
				if (cle > a->cles[i]) {
					i++;
				}
			}
			if( !(i<=a->nbCles ) && cle==a->cles[i]){
				a=insertionDansArbreRec(a->fils[i], cle);
			}
		}
	}

	return a;

}


Arbre* insererDansArbre(Arbre *a, int cle) {

	Arbre *pere;
	int i;

	if (a == NULL) {
		a = (Arbre *) malloc(sizeof(Arbre));

		a->nbCles = 1;
		a->nbFils = 0;

		a->cles[0] = cle;

		for (i = 1; i < NB_MAX_FILS; ++i) {
			a->cles[i]=NULL;
		}

	} else {
		if (a->nbCles == 3) {
			pere = (Arbre *) malloc(sizeof(Arbre));
			pere->nbCles = 0;
			pere->fils[0] = a;

			a = pere;

			a = eclatement(a, 0);
		}

		a = insertionDansArbreRec(a, cle);

	}

	return a;

}




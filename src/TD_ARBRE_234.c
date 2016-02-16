/*
 ============================================================================
 Name        : TD_ARBRE_234.c
 Author      : Anthony Geourjon
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arbre234.h"

int main(void) {

	printf("Création d'un arbre 2-4 avec 5 en racine.\n");

	Arbre *a = NULL;
	a=insererDansArbre(a,5);

	printf("5 est présent : %d\n", recherche(a, 6));
	printf("6 est présent : %d\n", recherche(a, 6));

	printf("Insertion de 6 puis 4.\n");

	a = insererDansArbre(a, 6);
	a = insererDansArbre(a, 4);

	printf("2 est présent : %d\n", recherche2(a, 2));
	printf("3 est présent : %d\n", recherche2(a, 3));
	printf("4 est présent : %d\n", recherche2(a, 4));
	printf("5 est présent : %d\n", recherche2(a, 5));
	printf("6 est présent : %d\n", recherche2(a, 6));

	printf("Le programme est correct jusqu'à present.\n");

	printf("Insertion de 3.\n");

	a = insererDansArbre(a, 3);

	printf("2 est présent : %d\n", recherche2(a, 2));
	printf("3 est présent : %d\n", recherche2(a, 3));
	printf("4 est présent : %d\n", recherche2(a, 4));
	printf("5 est présent : %d\n", recherche2(a, 5));
	printf("6 est présent : %d\n", recherche2(a, 6));

	printf("L'insertion de 3 casse l'intégrité de l'arbre et provque des pertes de données. Nous n'avons pu débogguer ce problème.\n");


	return EXIT_SUCCESS;
}

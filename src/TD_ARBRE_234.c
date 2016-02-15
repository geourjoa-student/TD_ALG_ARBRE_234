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


	Arbre *a = creerArbre(5);

	printf("5 est présent : %d\n", recherche(a, 6));

	a = insererDansArbre(a, 6);
	a = insererDansArbre(a, 4);
	a = insererDansArbre(a, 3);

	printf("5 est présent : %d\n", recherche(a, 5));
	printf("5 est présent : %d\n", recherche(a, 5));
	printf("6 est présent : %d\n", recherche2(a, 6));
	printf("6 est présent : %d\n", recherche2(a, 6));


	return EXIT_SUCCESS;
}

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

	printf("5 est présent : %d\n", recherche(a, 5));
	printf("5 est présent : %d\n", recherche2(a, 5));
	printf("%d", nbCles(a));

	return EXIT_SUCCESS;
}

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


	Arbre *a = creerArbre(6);

	printf("5 est présent : %d", recherche(a, 5));

	return EXIT_SUCCESS;
}

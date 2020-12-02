#include <stdlib.h>
#include <stdio.h>
#include "Tab.h"


int main() {
	int myTab1[10];
	int* myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));

	//On remplit le tableau avec des 0
	initTab(myTab2, TAB2SIZE);

	//On met dans le tableau les nombres de 1 à 20
	if (myTab2 != NULL) {
		for (int i = 0; i < 20; i++) {
			*(myTab2 + i) = i + 1;
		}
	}

	//Puis on affiche le tableau
	afficheTab(myTab2, TAB2SIZE, 100);
	printf("\n\n");

	//On ajoute un élément à la 101e case du tableau. Du coup on doit faire une réallocation de mémoire donc on
	// appelle la fonction ajoutElementDansTableau qui utilise realloc
	int size = TAB2SIZE;
	int nbElmts = 100;
	ajoutElementDansTableau(myTab2, &size, &nbElmts, 1);
	afficheTab(myTab2, size, 110);

	// On détruit le tableau
	free(myTab2);
}
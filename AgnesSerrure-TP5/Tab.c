#include <stdlib.h>
#include <stdio.h>
#include "Tab.h"


int initTab(int* tab, int tabSize) {
	// initTab est une fonction qui remplit un tableau d’entiers de taille size avec des zéros
	if (tabSize < 0 || tab == NULL) {
		return -1; //renvoie -1 si le tableau est vide ou si sa taille est négative
	}
	else {
		for (int i = 0; i < tabSize; i++) {
			*(tab + i) = 0; // sinon elle remplit le tableau avec des zéros
		}
		return tabSize; //et retourne la taille du tableau
	}
}

int afficheTab(int* tab, int size, int nbElts) {
	// afficheTab est une fonction qui affiche les nbElts premièrs éléments du tableau tab
	if (size <= 0 || tab == NULL || nbElts > size) {
		return -1; // comme avant, on renvoie -1 si le tableau est vide ou si sa taille est négative
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d  ", *(tab + i)); // sinon on affiche les éléments à l'aide du pointeur
		}
		return 0;
	}
}

int ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	// ajoute un nombre entier à la suite des valeurs déjà entrées 
	// et actualise le nombre d'éléments dans le tableau et la capacité du tableau
	if (*size <= 0 || tab == NULL) {
		return -1;
	}
	if (*nbElts >= *size) {
		//realloc sert à agrandir le tableau
		int* tab2 = (int*)realloc(tab, (TAILLEAJOUT + *size) * sizeof(int));
		if (tab2 == NULL) {
			return -1;
		}
		else {
			tab = tab2;
			// On initialise les dernières valeurs du nouveau tableau à 0
			for (int i = 0; i < TAILLEAJOUT; i++) {
				*(tab + i + *size) = 0;
			}
			*size += TAILLEAJOUT;
		}
	}
	// Ajout de l'élément à la place désirée
	*(tab + *nbElts) = element;
	return *nbElts + 1;
}
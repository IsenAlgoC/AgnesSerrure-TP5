#include <stdlib.h>
#include <stdio.h>
#include "Tab.h"


int initTab(int* tab, int tabSize) {
	// initTab est une fonction qui remplit un tableau d�entiers de taille size avec des z�ros
	if (tabSize < 0 || tab == NULL) {
		return -1; //renvoie -1 si le tableau est vide ou si sa taille est n�gative
	}
	else {
		for (int i = 0; i < tabSize; i++) {
			*(tab + i) = 0; // sinon elle remplit le tableau avec des z�ros
		}
		return tabSize; //et retourne la taille du tableau
	}
}

int afficheTab(int* tab, int size, int nbElts) {
	// afficheTab est une fonction qui affiche les nbElts premi�rs �l�ments du tableau tab
	if (size <= 0 || tab == NULL || nbElts > size) {
		return -1; // comme avant, on renvoie -1 si le tableau est vide ou si sa taille est n�gative
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d  ", *(tab + i)); // sinon on affiche les �l�ments � l'aide du pointeur
		}
		return 0;
	}
}

int ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	// ajoute un nombre entier � la suite des valeurs d�j� entr�es 
	// et actualise le nombre d'�l�ments dans le tableau et la capacit� du tableau
	if (*size <= 0 || tab == NULL) {
		return -1;
	}
	if (*nbElts >= *size) {
		//realloc sert � agrandir le tableau
		int* tab2 = (int*)realloc(tab, (TAILLEAJOUT + *size) * sizeof(int));
		if (tab2 == NULL) {
			return -1;
		}
		else {
			tab = tab2;
			// On initialise les derni�res valeurs du nouveau tableau � 0
			for (int i = 0; i < TAILLEAJOUT; i++) {
				*(tab + i + *size) = 0;
			}
			*size += TAILLEAJOUT;
		}
	}
	// Ajout de l'�l�ment � la place d�sir�e
	*(tab + *nbElts) = element;
	return *nbElts + 1;
}
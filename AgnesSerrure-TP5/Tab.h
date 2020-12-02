#pragma once

#define TAB2SIZE 100 //taille de myTab2
#define TAILLEAJOUT 50 

int initTab(int* tab, int tabSize);

int afficheTab(int* tab, int size, int nbElts);

int ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element);
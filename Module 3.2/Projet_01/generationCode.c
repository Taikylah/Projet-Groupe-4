#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"
#pragma warning(disable : 4996)

int ecrire_fichier_int; 
int global_int;

void ecrire_fichier(int param) { // apres le choix du mode creation du fichier param
	int i;
	FILE *pointeur = fopen("C:/Users/rania/OneDrive/Bureau/Projet/ARDUINO_C/param.h", "w+");

	if (pointeur == NULL)
	{
		printf("erreur \n");
		exit(-1);
	}

	fprintf(pointeur, "%s %d\n", "#define PARAM", param);
	fclose(pointeur);
}

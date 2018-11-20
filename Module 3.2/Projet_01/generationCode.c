#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"
#pragma warning(disable : 4996)

void ecrire_fichier(int param) { // apres le choix du mode creation du fichier param

	FILE *pointeur = fopen("C:/Users/Charles/Downloads/Projet-Groupe-4-master/Module 3.2/CoeurLed.Arduino/param.h", "w+");

	if (pointeur == NULL)
	{
		printf("erreur \n");
		exit(-1);
	}
	
	fprintf(pointeur, "%s %d\n", "#define PARAM", param);
	fprintf(pointeur, "%s %d\n", "#define LED", 0);
	fclose(pointeur);
}

void ecrire_led(int param) {

	FILE *pointeur = fopen("C:/Users/Charles/Downloads/Projet-Groupe-4-master/Module 3.2/CoeurLed.Arduino/param.h", "w+");
	int led;

	printf("Quelle LED voulez-vous allumer ? (numero du PIN) :");
	scanf("%d", &led);

	fprintf(pointeur, "%s %d\n", "#define PARAM", param);
	fprintf(pointeur, "%s %d\n", "#define LED", led);
}

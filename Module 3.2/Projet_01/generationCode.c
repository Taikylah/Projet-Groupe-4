#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"
#pragma warning(disable : 4996)

void ecrire_fichier(int param) { // apres le choix du mode creation du fichier param

	FILE *pointeur = fopen("C:/Users/Charles/Desktop/Projet-Groupe-4-master/Module 3.2/CoeurLed.Arduino/param.h", "w+"); // Créer le fichier param.h (ou le remplace)

	if (pointeur == NULL)
	{
		printf("erreur \n");
		exit(-1); // Quitte si le fichier ne parvient pas à être ouvert
	}
	
	fprintf(pointeur, "%s %d\n", "#define PARAM", param);
	fprintf(pointeur, "%s %d\n", "#define LED", 0); // écrit une ligne "#define LED 0" en plus dans le param.h afin d'initialiser la variable LED dans le programme Arduino
	fclose(pointeur);
}

void ecrire_led(int param) { // Fonction similaire à celle ci-dessus, permet en plus de demander la led que l'on veut allumer si on choisi le mode une led au choix

	FILE *pointeur = fopen("C:/Users/Charles/Desktop/Projet-Groupe-4-master/Module 3.2/CoeurLed.Arduino/param.h", "w+");
	int led;

	printf("Quelle LED voulez-vous allumer ? (numero du PIN) :");
	scanf("%d", &led);

	fprintf(pointeur, "%s %d\n", "#define PARAM", param);
	fprintf(pointeur, "%s %d\n", "#define LED", led);
}

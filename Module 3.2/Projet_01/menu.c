#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "generationCode.h"

#pragma warning(disable : 4996)
int afficher_menu() // interface de la fenetre elle affichera les choix suivants
{
	int a;
	printf("Choissisez votre mode de clignotement \n");
	printf("1: Mode Battement \n");
	printf("2: Mode Chenille\n");
	printf("3: Mode Un sur Deux\n");
	printf("4: Mode Un sur Trois\n");
	printf("5: Mode Une LED allumee au choix\n");
	printf("6: Mode transition\n");
	printf("7: Mode Un sur 2 chenille\n");
	printf("8: Mode Un sur 3 chenille\n");
	printf("Votre choix : ");
	scanf("%d", &a);

	if (a > 8) // si le choix et supérieur à 5 alors la fenêtre se fermera 
	{
		printf("erreur \n");
		exit(-1);
	}
	if (a == 5) // Si on veut une led au choix, on va demander quelle led allumer en appelant la fonction suivante
	{
		ecrire_led(a);
	}
	else
	{
		return a;
	}
}

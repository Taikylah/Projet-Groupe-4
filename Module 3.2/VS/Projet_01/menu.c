#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "generationCode.h"

#pragma warning(disable : 4996)
int afficher_menu() // interface de la fenetre elle affichera les choix suivant
{
	int a;
	printf("Choissisez votre mode de clignantement \n");
	printf("1: Mode Battement \n");
	printf("2: Mode Chennille\n");
	printf("3: Mode Un sur Deux\n");
	printf("4: Mode Un sur Trois\n");
	printf("5: Mode Une LED allumee au choix\n");
	printf("Votre choix : ");
	scanf("%d", &a);

	if (a > 5) // si le choix et supérieur à 5 alors la fentre se fermera 
	{
		printf("erreur \n");
		exit(-1);
	}
	else
	{
		return a;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "generationCode.h"
#pragma warning(disable : 4996)

int main() // 
{
	int choix;
	choix = afficher_menu();
	ecrire_fichier(choix);

	return 0;
}

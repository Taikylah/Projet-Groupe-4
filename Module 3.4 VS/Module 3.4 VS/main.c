#include <stdlib.h>
#include <stdio.h>
#include "donnees.h"
#include "actions.h"
#include "menu.h"
#pragma warning(disable : 4996)

int main()
{
	Donnees* tabdon = NULL;

	int nbr_lgn = nbr_lignes(); // Récupère le nombre de lignes renvoyées par la fonction nbr_lignes dans donnees.c

	tabdon = malloc(sizeof(Donnees) * nbr_lgn); // Allocation dynamique du tableau tabdon
	if (tabdon == NULL) // On vérifie si l'allocation a bien marché
	{
		exit(0); // On arrête tout
	}
	else
	{
		menu(tabdon); //Appelle la fonction menu dans menu.c afin d'afficher ce dernier
	}

	return 0;
}


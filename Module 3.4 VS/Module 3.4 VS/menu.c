#include <stdlib.h>
#include <stdio.h>
#include "donnees.h"
#include "actions.h"
#pragma warning(disable : 4996)

/* 
	Afficher les données dans l'ordre
	Afficher les données en ordre croissant
	"							" décroissant
	rechercher et afficher les données pour un temps particulier
	afficher la moyenne de pouls dans une plage de temps donnée
	afficher le nombre de lignes de données actuellement en mémoire
	Afficher le minimum/maximum de pouls avec le temps associé
*/

void menu(Donnees *tabdon)
{
	int m = -1;
	int j;
	int nbr_lgn = nbr_lignes();


	while (m != 0) // Si m vaut 0 on arrête le programme
	{
		printf("Que voulez-vous faire ?\n 1 : Lire les donnees du CSV\n 2 : Afficher les donnees dans l'ordre croissant du temps\n 3 : Afficher les donnees dans l'ordre decroissant du temps\n "
			"4 : Afficher les donnees dans l'odre croissant du pouls\n 5 : Afficher les donnees dans l'ordre decroissant du pouls\n 6 : Rechercher et afficher le pouls pour un temps particulier\n "
			"7 : Afficher la moyenne de pouls dans une plage de temps donnee\n 8 : Afficher le nombre de lignes de donnees actuellement en memoire\n 9 : Afficher le maximum de pouls avec le temps associe\n "
			"10: Afficher le minimum de pouls avec le temps associe\n 0 : Quitter\n");

		scanf("%i", &m);
		printf("\n"); //Permet un retour à la ligne pour une présentation plus propre
		lecturecsv(tabdon); //Apppelle la fonction de lecture du csv, ce qui permet d'initialiser le tableau avec les valeurs du csv, indispensable pour plusieurs des actions suivantes

		if (m == 1)
		{
			printf("Donnees du CSV : \n\n");
			
			for (j = 0; j < nbr_lgn; j++)
			{
				printf("%d;%.2f\n", tabdon[j].temps, tabdon[j].pouls); //Affiche les valeurs du tableau une par une jusqu'à ce qu'on atteigne le nombre de lignes du fichier
			}
		}

		if (m == 2)
		{
			printf("Donnees dans l'ordre croissant du temps : \n\n");

			tricroi_temps(tabdon); //Appelle la fonction de tri croissant pour le temps

			for (j = 0; j < nbr_lgn; j++)
			{
				printf("%d;%.2f\n", tabdon[j].temps, tabdon[j].pouls);
			}
		}

		if (m == 3)
		{
			printf("Donnees dans l'ordre decroissant du temps : \n\n");

			tridecroi_temps(tabdon); //Appelle la fonction de tri décroissant pour le temps

			for (j = 0; j < nbr_lgn; j++)
			{
				printf("%d;%.2f\n", tabdon[j].temps, tabdon[j].pouls);
			}
		}

		if (m == 4)
		{
			printf("Donnees dans l'odre croissant du pouls : \n\n");

			tricroi_pouls(tabdon); //Appelle la fonction de tri croissant pour le pouls

			for (j = 0; j < nbr_lgn; j++)
			{
				printf("%d;%.2f\n", tabdon[j].temps, tabdon[j].pouls);
			}
		}

		if (m == 5)
		{
			printf("Donnees dans l'ordre decroissant du pouls : \n\n");

			tridecroi_pouls(tabdon); //Appelle la fonction de tri décroissant pour le pouls

			for (j = 0; j < nbr_lgn; j++)
			{
				printf("%d;%.2f\n", tabdon[j].temps, tabdon[j].pouls);
			}
		}

		if (m == 6)
		{
			tricroi_temps(tabdon); //Permet d'avoir un tableau trié avant d'appeler l'algorithme de recherche
			recherche(tabdon);
		}

		if (m == 7)
		{
			tricroi_temps(tabdon); //Permet d'avoir un tableau trié avant de faire une moyenne
			moyenne(tabdon);
		}

		if (m == 8)
		{
			printf("%d lignes", nbr_lgn); //Affche le nombre de lignes grâce à la fonction nbr_lignes dans donnees.c
		}

		if (m == 9)
		{
			tridecroi_pouls(tabdon); //Je tri d'abord les donnees en ordre décroissant du pouls afin d'obtenir le pouls maximum dans la première case du tableau, avec le temps qui correspond

			printf("Le maximum de pouls est %.2f bpm a %d milisecondes", tabdon[0].pouls, tabdon[0].temps);
		}

		if (m == 10)
		{
			tricroi_pouls(tabdon); //Je tri d'abord les donnees en ordre croissant du pouls afin d'obtenir le pouls minimum dans la première case du tableau, avec le temps qui correspond

			printf("Le minimum de pouls est %.2f bpm a %d milisecondes", tabdon[0].pouls, tabdon[0].temps);
		}

		printf("\n\n"); //Permet une présentation plus propre
	}

	printf("Fin");
}


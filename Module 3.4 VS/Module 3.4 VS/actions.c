#include <stdlib.h>
#include <stdio.h>
#include "donnees.h"
#pragma warning(disable : 4996)

//J'utilise un algorthme de tri à bulles pour les fonctions de tri

void tricroi_temps(Donnees *tabdon) //Fonction de tri croissant en fonction du temps
{
	int tour = 0;
	int bool = 1; //Int booleen utilisé ensuite pour une boucle
	int i, temp;
	int nbr_lgn = nbr_lignes(); // Récupère le nombre de lignes renvoyées par la fonction nbr_lignes dans donnees.c

	while (bool)
	{
		bool = 0; // Permet de fermer la boucle lorsque i atteint le nombre de lignes du fichier
		tour++;

		for (i = 0; i < nbr_lgn - tour; i++)
		{
			if (tabdon[i].temps > tabdon[i + 1].temps) // On test si la valeur dans le tableau est plus grande que la valeur suivante, si elle l'est on les inverse
			{
				bool = 1; // Permet de relancer la boucle
				temp = tabdon[i].temps;					//Inversion pour les valeurs de temps
				tabdon[i].temps = tabdon[i + 1].temps;
				tabdon[i + 1].temps = temp;

				temp = tabdon[i].pouls;					//Inversion pour les valeurs de pouls
				tabdon[i].pouls = tabdon[i + 1].pouls;
				tabdon[i + 1].pouls = temp;
			}
		}
	}
}

void tridecroi_temps(Donnees *tabdon) // Fonction de tri similaire à la précédente pour trier en décroissant 
{
	int tour = 0;
	int bool = 1;
	int i, temp;
	int nbr_lgn = nbr_lignes(); // Récupère le nombre de lignes renvoyées par la fonction nbr_lignes dans donnees.c

	while (bool)
	{
		bool = 0;
		tour++;
		for (i = 0; i < nbr_lgn - tour; i++)
		{
			if (tabdon[i].temps < tabdon[i + 1].temps) // On test si la valeur dans le tableau est pus petite que la valeur suivante, à l'inverse de la fonction pour le tri croissant
			{
				bool = 1;
				temp = tabdon[i].temps;
				tabdon[i].temps = tabdon[i + 1].temps;
				tabdon[i + 1].temps = temp;

				temp = tabdon[i].pouls;
				tabdon[i].pouls = tabdon[i + 1].pouls;
				tabdon[i + 1].pouls = temp;
			}
		}
	}
}


void tricroi_pouls(Donnees *tabdon) //Fonction identique à celle du tri croissant pour le temps, cette fois pour le pouls
{
	int tour = 0;
	int bool = 1;
	int i, temp;
	int nbr_lgn = nbr_lignes(); // Récupère le nombre de lignes renvoyées par la fonction nbr_lignes dans donnees.c

	while (bool)
	{
		bool = 0;
		tour++;
		for (i = 0; i < nbr_lgn - tour; i++)
		{

			if (tabdon[i].pouls > tabdon[i + 1].pouls)
			{
				bool = 1;
				temp = tabdon[i].pouls;
				tabdon[i].pouls = tabdon[i + 1].pouls;
				tabdon[i + 1].pouls = temp;

				temp = tabdon[i].temps;
				tabdon[i].temps = tabdon[i + 1].temps;
				tabdon[i + 1].temps = temp;
			}

		}

	}
}


void tridecroi_pouls(Donnees *tabdon) //Fonction identique à celle du tri décroissant pour le temps, cette fois pour le pouls
{
	int tour = 0;
	int bool = 1;
	int i, temp;
	int nbr_lgn = nbr_lignes(); // Récupère le nombre de lignes renvoyées par la fonction nbr_lignes dans donnees.c

	while (bool)
	{
		bool = 0;
		tour++;
		for (i = 0; i < nbr_lgn - tour; i++)
		{

			if (tabdon[i].pouls < tabdon[i + 1].pouls)
			{
				bool = 1;
				temp = tabdon[i].pouls;
				tabdon[i].pouls = tabdon[i + 1].pouls;
				tabdon[i + 1].pouls = temp;

				temp = tabdon[i].temps;
				tabdon[i].temps = tabdon[i + 1].temps;
				tabdon[i + 1].temps = temp;
			}

		}

	}
}


void recherche(Donnees *tabdon) //Algorithme de recherche séquentielle
{
	int vRecherche;
	int e, i;
	int nbr_lgn = nbr_lignes(); // Récupère le nombre de lignes renvoyées par la fonction nbr_lignes dans donnees.c

	printf("Entrez le temps en milisecondes que vous voulez rechercher : \n");
	scanf("%d", &vRecherche);

	e = 0;
	for (i = 0; i < nbr_lgn; i++) //On incrémente i tant que la valeur recherchée n'est pas trouvée
	{
		if (tabdon[i].temps == vRecherche)
		{
			e = 1;
			break; // Arrête la boucle lorsque la valeur recherchée est trouvée
		}
	}

	if (e == 1) // e(int booleen) prends la valeur 1 si on trouve la valeur recherchée
	{
		printf("Le pouls pour ce temps est de %.0f bpm\n", tabdon[i].pouls);
	}
	else
	{
		printf("Une valeur de pouls pour ce temps n'existe pas\n");
	}
}


void moyenne(Donnees *tabdon) //Fonction qui calcul la moyenne entre 2 nombres donnés
{
	int somme = 0;
	int resultat;
	int i;
	int nbr1, nbr2;
	int d = 0;

	printf("Calculer la moyenne du pouls entre quelles valeurs du tableau ?\n");
	scanf("%i", &nbr1);
	printf("et ?\n");
	scanf("%i", &nbr2);

	if (nbr2 - nbr1 <= 0) // On veut 2 valeurs croissantes pour pouvoir incrémenter correctement ensuite
	{
		printf("Impossible, donnez les nombres dans l'ordre croissant");
	}
	else
	{
		for (i = nbr1; i <= nbr2; i++) // On incrémente tant que nbr1 est inférieur ou égal au nbr2 afin d'obtenir la somme de toutes la valeurs de pouls entre les deux
		{
			somme = somme + tabdon[i].pouls;
			d = d + 1; // On incrémente d afin d'obtenir le dividende pour l'opération de la moyenne
		}
		resultat = somme / d;

		printf("Moyenne du pouls entre %i et %i : %i bpm", nbr1, nbr2, resultat);
	}
}
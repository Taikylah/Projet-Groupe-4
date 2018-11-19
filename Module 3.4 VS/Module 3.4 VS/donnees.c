#include <stdlib.h>
#include <stdio.h>
#include "donnees.h"
#pragma warning(disable : 4996)


int nbr_lignes() //compte le nombre de ligne du fichier csv
{
	FILE *csv = fopen("C:\\Users\\Vincent\\Documents\\GitHub\\Projet-Groupe-4\\Module 3.4 VS\\Module 3.4 VS\\ConvertisseurSerialCSV\\Battements.csv", "r"); // Ouvre le .csv
	int c;
	int nbr_lgn = 0;
	while ((c = fgetc(csv)) != EOF) // Lit le nombre de lignes jusqu'à ce que fgetc renvoie EOF (fin du fichier)
	{
		if (c == '\n')
			nbr_lgn++; // On incrémente le nombre de lignes chaque fois qu'on en lit une nouvelle
	}

	fclose(csv); // Libère la mémoire allouée pour le chargement du fichier
	return nbr_lgn;
}


int lecturecsv(Donnees *tabdon)
{
	FILE* csv = NULL;
	
	csv = fopen("C:\\Users\\Vincent\\Documents\\GitHub\\Projet-Groupe-4\\Module 3.4 VS\\Module 3.4 VS\\ConvertisseurSerialCSV\\Battements.csv", "r"); 
	int i = 0;
	int nbr_lgn = nbr_lignes();  // Récupère le nombre de lignes renvoyées par la fonction ci-dessus

	if (csv == NULL)
	{
		printf("impossible d'ouvrir le csv\n"); // Vérifie que le fichier est bien ouvert
	}
	else
	{		
		for (i=0;i<nbr_lgn;i++)
		{
 			fscanf(csv, "%d;%f", &(tabdon[i].temps), &(tabdon[i].pouls)); // Rempli mon tableau de structure "tabdon" avec les valeurs du csv
		}

		fclose(csv);
	}
	return 0;
}
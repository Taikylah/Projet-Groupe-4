#pragma once

typedef struct Donnees Donnees;

struct Donnees // Structure de donn�es utilis�es dans mon tableau "tabdon"
{
	int temps;
	int pouls;
};

int lecturecsv(Donnees *tabdon);
int nbr_lignes();



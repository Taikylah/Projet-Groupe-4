#pragma once

typedef struct Donnees Donnees;

struct Donnees // Structure de données utilisées dans mon tableau "tabdon"
{
	int temps;
	float pouls;
};

int lecturecsv(Donnees *tabdon);
int nbr_lignes();



#include "Arduino.h"  //On inclut le système Arduino dans notre programme
#include "cardio.h"   //On inclut notre fichier cardio.h qui nous permet d'appeler les fonctions que nous avons créer

unsigned long time;
float LEDPouls = A0;
float Compteur = 0;                   //Déclarations des différents variables.
unsigned long condition = 10000;

void rdy(){                          //Fonction rdy(), permettant de définir la LED en sortie
  pinMode(LEDPouls, OUTPUT);
}

void pret(){                        //Fonction pret()
 time = millis();                   //On déclare la fonction millis() dans la variable time 
  delay(300);                       //On attends 3secondes
  LEDPouls = analogRead(A0);        //L'état de la LED est lu par le port analogique A0
  
}

float LEDPoul(){
    if(LEDPouls > 0 && time <= condition) {  //Première condition il faut que la LED soit allumé et que le temps soit inférieur ou égal à la condition
      Compteur = Compteur+1;                 //Cela permet d'incrémenter le compteur de battements de 1 à chaque tours.
      
    }
}
void affichage(){                           //Fonction de l'affichage des valeurs
  if(time > condition){                     //Deuxième fonction, le temps doit être supérieur à la condition afin de pouvoir accéder au lignes suivantes
      Compteur = Compteur*6;                //A la fin de l'incrémentation on multiplie par 6 afin d'avoir les battements par minutes
      Serial.print(millis());               //On affiche la valeur de la fonction millis() soit le temps en ms depuis le début du programme
      Serial.print(";");                    //On sépare par un point virgule 
      Serial.println(Compteur);             //On affiche la valeur du Compteur soit les battements par minutes.
      condition = condition + 10000;        //On augmente la condition de 10 000 afin de pouvoir rentrer dans la boucle toutes les 10s
      Compteur = 0;                         //On passe la variable Compteur à 0 pour réinitialiser le programme
 }    
}

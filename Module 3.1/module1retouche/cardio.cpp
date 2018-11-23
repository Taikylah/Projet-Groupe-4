#include "Arduino.h"
#include "cardio.h"

#define potentio A0                      
int valeur = 0;
int Compteur = 0;
unsigned long time;
unsigned long cond = 10000;
int battements;
int Bpm;

void set(){ 
  time = millis();                            // Utilisation de la fonction millis afin de connaître l'heure 
  valeur = analogRead(potentio);              // On lit en analogique la valeur du potentiomètre 
  battements = map(valeur, 0, 1023, 0, 1023); // La valeur du potentiomètre est disponible entre 0 et 1023
  delay(250);
}

void calcul(){
  if(battements > 700 && time <=cond){
    Compteur = Compteur + 1;                            
    Bpm = Compteur;
     
  }
}
void affichagebpm(){
   if(time > cond){ 
    Bpm = Bpm * 6;                          //On multiplie le nombre de battements obtenu en 10s par 6 pour avoir des battements par minutes
    Serial.print(time);                    //On affiche le résultat
    Serial.print(";");
    Serial.println(Bpm);
                      //On remet les compteurs à zéro.
    cond = cond + 10000;                   //On augmente cond de 10s pour avoir d'autres valeurs à 10s d'intervalles à chaque fois 
    Bpm = 0;
    
   }
}

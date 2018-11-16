#include "Arduino.h"
#include "cardio.h"

unsigned long time;
float LEDPouls = A0;
int Compteur = 0;

void rdy(){
  pinMode(LEDPouls, OUTPUT);
}

void pret(){
 time = millis();
  delay(300);
  LEDPouls = analogRead(A0);
}

float LEDPoul(){
  
    if(LEDPouls > 0 && time <= 2000) {
      Compteur = Compteur+1;
    }
}
void affichage(){
   if(time>2000 && time<2200){
      Compteur = Compteur*30;
      Serial.print("La fréquence cardiaque est de ");
      Serial.print(Compteur);
      Serial.println(" Battement par minutes");
      Serial.print("Le programme a été lancé pendant ");
      Serial.print(time);
      Serial.println(" ms");
      Serial.println("Merci de relancer le programme pour de nouvelle mesure");
 }
}

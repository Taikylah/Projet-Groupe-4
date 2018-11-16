#include "cardio.h"


void setup(){
  Serial.begin(9600);                    
}

void loop(){
  rdy();
  pret();
 LEDPoul(); 
 affichage();
  }

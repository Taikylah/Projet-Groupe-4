#include "cardio.h"


void setup() {
Serial.begin(9600);

}

void loop() {
  set();
  calcul();                          //appels des fonctions de cardio.cpp
  affichagebpm();
}

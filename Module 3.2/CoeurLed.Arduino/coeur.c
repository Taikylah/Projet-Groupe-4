#include  "coeur.h"
#include "Arduino.h"
#include "param.h"

int j;
int n;
void mode() {

  for (n = 4; n <= 13; n++) {
    pinMode(n, OUTPUT);
  }

  // put your main code here, to run repeatedly:

  switch (PARAM) {

    case 1: {   //quand PARAM = 1 alors elle actionnera la fonction battement, toutes les Leds s'allument et s'éteignent en même temps
        for (n = 4; n <= 13; n++) {
          digitalWrite (n, HIGH);
          delay(500);
          digitalWrite (n, LOW);
          delay(500);
        }
        break;
      }
    case 2: { //quand PARAM = 2 alors elle actionnera fonction chenille allume et éteinds les Led progrssivement
        for (byte n = 4 ; n <= 13 ; n++) {
          digitalWrite (n, HIGH) ; // allume la DEL sur broche i
          delay (500) ; // durée du flash 50 millisecondes
          digitalWrite (n, LOW) ; // éteint la DEL
        }
        break;
      }
    case 3: { //quand PARAM = 3 alors elle actionnera fonction allumage des Led une sur deux
        for (int n = 4 ; n <= 13; n++) {
          int j = n + 1 ;
          digitalWrite(n, LOW);
          digitalWrite(j , HIGH);
          delay(500);
        }
        break;
      }
    case 4: { // quand PARAM = 4 alors elle actionnera fonction allumage des Led une sur tois
        for (int n = 4 ; n <= 13; n++) {
          int j = n + 3 ;
          digitalWrite(n, LOW);
          digitalWrite(j , HIGH);
          delay(500);
        }
        break;
      }
    case 5: {
        for (int n = LED); {
          digitalWrite(n, HIGH);
          delay(500);
          digitalWrite(n, LOW);
          delay(500);
        }
      }

  }
}

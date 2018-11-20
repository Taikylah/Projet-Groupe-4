#include  "coeur.h"
#include "Arduino.h"
#include "param.h"

int j;
int n;
// put your main code here, to run repeatedly:

void battement() //quand PARAM = 1 alors elle actionnera la fonction battement, toutes les Leds s'allument et s'éteignent en même temps
{
  for (n = 4; n <= 13; n++) {
    digitalWrite (n, HIGH);
  }
  delay(500);
  for (n = 4; n <= 13; n++) {
    digitalWrite (n, LOW);
  }
  delay(500);
}
void chenille()  //quand PARAM = 2 alors elle actionnera fonction chenille allume et éteinds les Led progrssivement
{
  for (n = 4 ; n <= 13 ; n++) {
    digitalWrite (n, HIGH) ; // allume la DEL sur broche i
    delay (500) ; // durée du flash 50 millisecondes
    digitalWrite (n, LOW) ; // éteint la DEL
  }
}
void unsurdeux() //quand PARAM = 3 alors elle actionnera fonction allumage des Led une sur deux
{
  n = 4;
  while ( n != 0) {
    digitalWrite(4 , HIGH);
    digitalWrite(6 , HIGH);
    digitalWrite(8 , HIGH);
    digitalWrite(10 , HIGH);
    digitalWrite(12 , HIGH);
    delay(500);
    digitalWrite(4 , LOW);
    digitalWrite(6 , LOW);
    digitalWrite(8 , LOW);
    digitalWrite(10 , LOW);
    digitalWrite(12 , LOW);
    delay(500);
  }
}
void unsurtrois() // quand PARAM = 4 alors elle actionnera fonction allumage des Led une sur trois
{
  n = 4;
  while ( n != 0) {
    digitalWrite(4 , HIGH);
    digitalWrite(7 , HIGH);
    digitalWrite(10 , HIGH);
    digitalWrite(13 , HIGH);
    delay(500);
    digitalWrite(4 , LOW);
    digitalWrite(7 , LOW);
    digitalWrite(10 , LOW);
    digitalWrite(13 , LOW);
    delay(500);
  }
}
void uneLedauchoix()
{
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}

void transition()
{
  for (n = 4; n <= 13; n++) {
    j = n + 1;
    digitalWrite(n, HIGH);
    digitalWrite(j, HIGH);
    delay(500);
    digitalWrite(n, LOW);
    digitalWrite(j, LOW);
    delay(500);
    delay(500);
  }
}

void unsurdeuxchenille()
{
  for (n = 4; n <= 13; n++) {
    n++;
    digitalWrite(n, HIGH);
    delay(500);
    digitalWrite(n, LOW);
    delay(500);
  }

}
void unsurtroischenille()
{
  for (n = 2; n <= 13; n++) {
    n = n+2;
    digitalWrite(n, HIGH);
    delay(500);
    digitalWrite(n, LOW);
    delay(500);
  }

}

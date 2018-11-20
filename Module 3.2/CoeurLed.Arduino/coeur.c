#include  "coeur.h"
#include "Arduino.h"
#include "param.h"

int j;
int n;
// put your main code here, to run repeatedly:

void battement() //toutes les Leds s'allument et s'éteignent en même temps
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
void chenille()  //allume et éteind les Led progressivement
{
  for (n = 4 ; n <= 13 ; n++) {
    digitalWrite (n, HIGH) ; // allume la DEL sur broche i
    delay (500) ; // durée du flash 50 millisecondes
    digitalWrite (n, LOW) ; // éteint la DEL
  }
}
void unsurdeux() //allume une Led sur deux et les fait clignoter
{
  n = 4; //tricky, permet d'avoir une boucle while infinie
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
void unsurtrois() // allume une Led sur trois et les fait clignoter
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
void uneLedauchoix() // allume la led choisie lors de la création du param.h
{
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}

void transition() // Allume les leds 2 par 2 et les fait clignoter en avançant progressivement
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

void unsurdeuxchenille() // Allume une led sur deux en mode chenille
{
  for (n = 4; n <= 13; n++) {
    n++;
    digitalWrite(n, HIGH);
    delay(500);
    digitalWrite(n, LOW);
    delay(500);
  }

}
void unsurtroischenille() // Allume une led sur trois en mode chenille
{
  for (n = 2; n <= 13; n++) {
    n = n+2;
    digitalWrite(n, HIGH);
    delay(500);
    digitalWrite(n, LOW);
    delay(500);
  }

}

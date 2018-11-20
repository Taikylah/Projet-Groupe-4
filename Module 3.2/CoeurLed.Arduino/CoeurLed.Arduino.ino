#include "coeur.c"
#include "param.h"
void setup () { // declaration des led
  for (int n = 4; n <= 13; n++)
  {
    pinMode(n, OUTPUT); // défini les pins en sortie
  }
  for (int n = 4; n <= 13; n++) // eteindre toutes les led (si anomalie)
    digitalWrite(n, LOW);
}

void loop () { // tout les mode
  switch (PARAM) {
    case 1: {
        battement ();
        break;
      }
    case 2: {
        chenille ();
        break;
      }
    case 3: {
        unsurdeux ();
        break;
      }
    case 4: {
        unsurtrois ();
        break;
      }
    case 5: {
        uneLedauchoix ();
        break;
      }
    case 6: {
        transition();
        break;
      }
    case 7: {
        unsurdeuxchenille();
        break;
      }
    case 8: {
        unsurtroischenille();
        break;
      }
  }
}

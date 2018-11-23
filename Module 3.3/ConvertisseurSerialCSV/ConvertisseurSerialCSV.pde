//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;  // import de la librairie 

//declare
PrintWriter output;   //definition du type de connection
Serial udSerial;      //definition du nom de la liaison serie

void setup() {
  udSerial = new Serial(this, "COM6 ", 9600);  // definition du port et de la vitesse de connection
  output = createWriter ("Battements.csv");             // creation du fichier
}

  void draw() {
    if (udSerial.available() > 0) {//si il y a des données qui arrivent sur la  serie
      String SenVal = udSerial.readStringUntil('\n'); // stockage des données dans une variable
      if (SenVal != null){                  // Si il y a des données dans la vaiable
        output.print(SenVal);              // archivage des données dans le fichier
      }
    }
  }

  void keyPressed(){ // a la pression d'une touche faire :
    output.flush();  //  vidage des donnes et ajout dans le fichier
    output.close();  // fermeture de la liaison serie
    exit();          // fermeture du programme
  }

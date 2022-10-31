#include <SD.h>
#include <Wire.h>

File logFile;

void setup()
{
  
  // initialisation de la carde SD
  Serial.print(F("Iniciando SD ..."));
  if (!SD.begin(10))
  {
    Serial.println(F("Error al iniciar"));
    return;
  }
  Serial.println(F("Iniciado correctamente"));
}


void loop()
{
  // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
         
    // check if returns are valid, if they are NaN (not a number) then something went wrong!
   
  
  // Abrir archivo et écrire dans la console de l'ordinateur
  
  Serial.print(", Humidité en % =");
  Serial.println("");
       
  
  char time_output[30];
  delay(1000);
  
  logFile = SD.open("datalog.txt", FILE_WRITE);

  // Ecrire sur la carte SD les valeurs du temps, humidité et température
  if (logFile) { 
        logFile.print("Temps en (ms)=");
        logFile.print(millis());
        logFile.print(", Température en ºC =");
        logFile.println(" ");
        logFile.close();
  
  } 
  else {
    Serial.println("Error al abrir el archivo");
  }
  delay(500);
}

#include <SD.h>
#include "SparkFun_SGP30_Arduino_Library.h" 
#include <Wire.h>
#include "DHT.h"
#define DHTPIN 2     // DHT Pro an Stecksockel D2
#define DHTTYPE DHT22   // DHT 22  (AM2302)

const int Sensor;
DHT dht(DHTPIN, DHTTYPE);

#define _NUMER0_BROCHE_ANALOGIQUE A1


SGP30 mySensor; //create an object of the SGP30 class
int intensitelum; 
File logFile;

void setup()
{
  pinMode(Sensor,INPUT);
  Serial.begin(9600);
  //Initialize sensor SGP30 de CO2
  Wire.begin();
  if (mySensor.begin() == false) 
  {
    Serial.println("No SGP30 Detected. Check connections.");
    while (1);
  }
  //Initializes sensor for air quality readings
  //measureAirQuality should be called in one second increments after a call to initAirQuality
  mySensor.initAirQuality();

  // initialisation de la carde SD
  Serial.print(F("Iniciando SD ..."));
  if (!SD.begin(10))
  {
    Serial.println(F("Error al iniciar"));
    return;
  }
  Serial.println(F("Iniciado correctamente"));
  dht.begin();
}


// Funcion que simula la lectura de un sensor

void loop()
{
  // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    float t = dht.readTemperature();
     
    // check if returns are valid, if they are NaN (not a number) then something went wrong!
    if (isnan(t) || isnan(h)) 
    {
        Serial.println("Problème lecture DHT22");
    } 
    else 
    {
                              
     }
  
  // Abrir archivo et écrire dans la console de l'ordinateur
  
  Serial.print("Température en ºC =");
  Serial.print(t);
  Serial.print(", Humidité en % =");
  Serial.print(h);
  Serial.println("");
   //Serial.print(DHT.temperature);
  //Serial.print(", Humidity = ");
  //Serial.print(DHT.humidity);
  intensitelum = analogRead(A0);
  Serial.print(", Intensité lumineuse = ");
  Serial.println(intensitelum);

  float tension=analogRead(_NUMER0_BROCHE_ANALOGIQUE) ;
  //Conversion de la tension numérique en tension analogique
   float tension_lue=tension*5.0/1023 ;
  //Calcul de la pression à partir de "tension_lue" pour le capteur
  float pression = tension_lue *760.0 + 400.0 ; 
  Serial.print("Pression = ");
  Serial.print(pression, 1);
  Serial.println(" hPa");

  
  //Catpeur de CO2: First fifteen readings will be
  //CO2: 400 ppm  TVOC: 0 ppb
  //measure CO2 and TVOC levels
  mySensor.measureAirQuality();
  Serial.print(", CO2 en ppm: ");
  Serial.print(mySensor.CO2);
  Serial.print(", TVOC en ppb: ");
  Serial.print(mySensor.TVOC);
    Serial.println("");
  // il faut rajouter ici le programme du capteur de pression grove

  char time_output[30];
  delay(1000);
  
  logFile = SD.open("datalog.txt", FILE_WRITE);

  // Ecrire sur la carte SD les valeurs du temps, humidité et température
  if (logFile) { 
        logFile.print("Temps en (ms)=");
        logFile.print(millis());
        logFile.print(", Température en ºC =");
        logFile.print(t);
        logFile.print(", Humidité en % =");
        logFile.print(h);
        logFile.println("");
        logFile.print(", Intensité lumineuse =");
        logFile.print(intensitelum);
        logFile.print(", Pression en hPa = ");
        logFile.print(pression, 1);
        logFile.print(", CO2 en ppm =");
        logFile.println(mySensor.CO2);
        logFile.print(", TVOC en ppb =");
        logFile.print(mySensor.TVOC);
        logFile.println(" ");
        logFile.close();
  
  } 
  else {
    Serial.println("Error al abrir el archivo");
  }
  delay(500);
}

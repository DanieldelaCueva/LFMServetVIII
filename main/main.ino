/*

ARDUINO SERVET VIII
LYCÉE MOLIÈRE ZARAGOZA

*/

// Library importation

  //SD library
  #include <SD.h>
  #include <Wire.h>

  //TEMP+HUM library (DHT22)
  #include <DHT.h>

  #define DHTPIN 2
  #define DHTTYPE DHT22

// Used pins declaration

// Global variables
File logFile;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  // SD card initialization
  Serial.print(F("Starting SD card"));
  if (!SD.begin(10))
  {
    Serial.println(F("Error starting SD card"));
    return;
  }
  Serial.println(F("SD card started successfully")); 
}

void loop() {
  // temp + hum read
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)){
      Serial.print("Error reading DHT22");
  }
  
   // opens or creates file datalog.txt to write it
   logFile = SD.open("datalog.txt", FILE_WRITE);

   // writes time from script's start in ms if the file is successfully opened, prints error otherwise
   if (logFile) { 
    logFile.print("Time (ms): ");
    logFile.println(millis());
    logFile.print("Temperature (ºC): ");
    logFile.println(t);
    logFile.print("Humidity (%): ");
    logFile.println(h);
  
  } else {
    Serial.println("Error opening the file");
  }
  delay(500);
}

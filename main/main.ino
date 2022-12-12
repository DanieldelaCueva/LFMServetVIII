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

  
  //AIR QUALITY LIBRARY (SGP30)
  #include <SparkFun_SGP30_Arduino_Library.h>

  #define DHTPIN 2
  #define DHTTYPE DHT22

// Used pins declaration

// Global variables
File logFile;

DHT dht(DHTPIN, DHTTYPE);

SGP30 airQSensor;

void setup() {
  Serial.begin(9600);

  
  // Air quality sensor initialization
  airQSensor.initAirQuality();

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
  delay(100);

  // temp + hum read
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)){
      Serial.print("Error reading DHT22");
  }

  // Air quality measure, variables .TVOC and .CO2 assigned. First 15 readings are default
  airQSensor.measureAirQuality();
  
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
    logFile.print("CO2 (ppm): ");
    logFile.println(airQSensor.CO2);
    logFile.print("TVOC (ppb): ");
    logFile.println(airQSensor.TVOC);
    logFile.close();
  
  } else {
    Serial.println("Error opening the file");
  }
  delay(500);
}

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

float tension, pressure;  // pressure sensor variables

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

  // Data format prompt creation, to write in an understandable way for the visualization script
  logFile = SD.open("datalog.txt", FILE_WRITE);
  if(logFile){
    logFile.println("Time (ms): ");
    logFile.println("Temperature (ºC): ");
    logFile.println("Humidity (%): ");
    logFile.println("Pressure (hPa): ");
  } else {
    Serial.println("Error opening the file");
  }

}

void loop() {
  // temp + hum read
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)){
      Serial.print("Error reading DHT22");
  }

  // pressure sensor reading and signal conversion
  tension = analogRead(A0) * 5.0 / 1023.0; 
  pressure = tension * 760.0 + 500.0;
  
  // opens or creates file datalog.txt to write it
  logFile = SD.open("datalog.txt", FILE_WRITE);

  // writes sensors readings to the SD card if the file is successfully opened, prints error otherwise
  if (logFile) {
    logFile.println(millis());
    logFile.println(t);    
    logFile.println(h);
    logFile.println(pressure); 
    logFile.close(); 
  } else {
    Serial.println("Error opening the file");
  }

  // writes sensors readings to the serial monitor
  Serial.print("Time (ms): ");
  Serial.println(millis());
  Serial.print("Temperature (ºC): ");
  Serial.println(t);
  Serial.print("Humidity (%): ");
  Serial.println(h);
  Serial.print("Pressure (hPa): ");
  Serial.println(pressure);

  delay(2000);
}

/*

ARDUINO SERVET VIII
LYCÉE MOLIÈRE ZARAGOZA

*/

// Library importation
#include <SD.h>

// Used pins declaration

// Global variables


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

    // opens or creates file datalog.txt to write it
    logFile = SD.open("datalog.txt", FILE_WRITE);

    // writes time from script's start in ms if the file is successfully opened, prints error otherwise
    if (logFile) { 
        logFile.print("Time (ms)=");
        logFile.println(millis());
        logFile.close();
  
  } else {
    Serial.println("Error opening the file");
  }
}

/*

ARDUINO SERVET VIII
LYCÉE MOLIÈRE ZARAGOZA

*/

// Library importation

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

void loop() {}

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
const int UV_CONTROL_ANALOG_PIN = A1;
const int UV_EXP_ANALOG_PIN = A2;

const int BLUE_LED_PIN = 8; // heartbeat pin

// Global variables
File logFile;

DHT dht(DHTPIN, DHTTYPE);

float tension, pressure;  // pressure sensor variables

void setup() {
  Serial.begin(9600);

  // Heartbeat pin init
  pinMode(BLUE_LED_PIN, OUTPUT);

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
    logFile.println("UV control index: ");
    logFile.println("UV experiment index: ");
    logFile.close();
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

  // UV control measuing
  float control_sensor_output = analogRead(UV_CONTROL_ANALOG_PIN);
  float UV_control_value;
  if (round(control_sensor_output / 100) - 1 >= 0){
    UV_value = round(control_sensor_output / 100) - 1;
  } else {
    UV_value = round(control_sensor_output / 100);
  }

  // UV experiment measuing
  float exp_sensor_output = analogRead(UV_EXP_ANALOG_PIN);
  float UV_exp_value;
  if (round(control_exp_output / 100) - 1 >= 0){
   UV_exp_value = round(control_exp_output / 100) - 1;
  } else {
   UV_exp_value = round(control_exp_output / 100);
  }
  
  // opens or creates file datalog.txt to write it
  logFile = SD.open("datalog.txt", FILE_WRITE);

  // writes sensors readings to the SD card if the file is successfully opened, prints error otherwise
  if (logFile) {
    digitalWrite(BLUE_LED_PIN, LOW);
    logFile.println(millis());
    logFile.println(t);    
    logFile.println(h);
    logFile.println(pressure); 
    logFile.println(UV_control_value);
    logFile.println(UV_exp_value);
    logFile.close(); 
  } else {
    Serial.println("Error opening the file");
  }

  digitalWrite(BLUE_LED_PIN, HIGH);

  // writes sensors readings to the serial monitor
  Serial.print("Time (ms): ");
  Serial.println(millis());
  Serial.print("Temperature (ºC): ");
  Serial.println(t);
  Serial.print("Humidity (%): ");
  Serial.println(h);
  Serial.print("Pressure (hPa): ");
  Serial.println(pressure);
  Serial.print("UV control index: ");
  Serial.println(UV_control_value);
  Serial.print("UV exp index: ");
  Serial.println(UV_exp_value);

  delay(2000);
}

int piezoPin = 5; // Piezo on Analog Pin 5
int piezoPin2 =4; // Piezo on Analog Pin 5
int threshold = 120; // The sensor value to reach before

int sensorValue = 0; // A variable to store the value read from
int sensorValue2 = 0; // A variable to store the value read from
const long numReadings = 10;
long readings[numReadings];
long index = 0;
long total = 0;
long average = 0;
String output1 = "s1";

void setup() {
  Serial.begin(9600);
}
void loop() {

   sensorValue = analogRead(piezoPin); // Read the value from the sensor
   //sensorValue2 = analogRead(piezoPin2); // Read the value from the sensor
   delay(10);

   Serial.println(sensorValue); // send the response in return
  
}

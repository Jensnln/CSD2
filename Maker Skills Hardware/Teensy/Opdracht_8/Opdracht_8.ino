int sensorPin = A0; // select the input pin for the potentiometer
const int ledPin = 23; // select the pin for the LED
// Pin 13: Arduino has an LED connected on pin 13
// Pin 11: Teensy 2.0 has the LED on pin 11
// Pin 6: Teensy++ 2.0 has the LED on pin 6
// Pin 13: Teensy 3.0 has the LED on pin 13
int sensorValue = 0; // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200); // extra so we can check the analogue value
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue); // print the analogue value to the serial monitor
  // turn the ledPin on
  analogWrite(ledPin, sensorValue / 1024.0 * 255);
  delay(1);
}

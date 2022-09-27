bool switcher = 0;
int lastsensorVal = 0;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(23, OUTPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);
  //print out the value of the pushbutton
  Serial.println(sensorVal);



  if (sensorVal == 0 && lastsensorVal == 1) {
    switcher = !switcher;
  }


  if (switcher == 0) {
    digitalWrite(23, LOW);
  } else {
    digitalWrite(23, HIGH);
  }


  lastsensorVal = sensorVal;
  Serial.println("Last Sensor val: " + lastsensorVal);
//  delay(5);
}

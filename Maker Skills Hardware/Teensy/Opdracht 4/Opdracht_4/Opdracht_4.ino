const int pin =  23;
void setup() { 
  pinMode(pin, OUTPUT);
}

void loop() {
  for (int x = 0; x < 256; x++) {
    analogWrite(pin, x);
    delay(25);
  }
}

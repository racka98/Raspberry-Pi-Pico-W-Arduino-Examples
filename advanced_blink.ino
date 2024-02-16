// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(16, HIGH);  // turn the LED on (HIGH is the voltage level)
  //digitalWrite(17, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);             // wait for a second

  digitalWrite(16, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(17, HIGH);
  //digitalWrite(LED_BUILTIN, LOW);
  delay(1000);             // wait for a second

  //digitalWrite(16, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(17, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);             // wait for a second                   // wait for a second
}

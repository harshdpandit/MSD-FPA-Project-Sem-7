int relay_pin_1 = 14;
int relay_pin_2 = 13;
int relay_pin_3 = 12;
int relay_pin_4 = 26;

//int relay_pin_4 = 18;
void setup() {
  // put your setup code here, to run once:
  pinMode(relay_pin_1, OUTPUT);
  pinMode(relay_pin_2, OUTPUT);
  pinMode(relay_pin_3, OUTPUT);
  pinMode(relay_pin_4, OUTPUT);
  //pinMode(relay_pin_4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay_pin_1, LOW);
  digitalWrite(relay_pin_2, LOW);
  digitalWrite(relay_pin_3, LOW);
  digitalWrite(relay_pin_4, LOW);
  //digitalWrite(relay_pin_4, LOW);
  delay(1000);
  digitalWrite(relay_pin_1, HIGH);
  digitalWrite(relay_pin_2, HIGH);
  digitalWrite(relay_pin_3, HIGH);
  digitalWrite(relay_pin_4, HIGH);
  //digitalWrite(relay_pin_4, HIGH);
  delay(1000);

}

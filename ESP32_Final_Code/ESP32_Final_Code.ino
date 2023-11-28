#define RST_PIN         22          
#define SS_PIN          5 
#define Piston1         14
#define Piston2         12
#define Piston3         13

#define IR              2 
#define IN1             26
#define IN2             25
#include <SPI.h>
#include <MFRC522.h>
MFRC522 mfrc522(SS_PIN, RST_PIN); 
void setup() {
 // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Piston1,OUTPUT);
pinMode(Piston2,OUTPUT);
pinMode(Piston3,OUTPUT);

pinMode(IR,INPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
SPI.begin();			// Init SPI bus
mfrc522.PCD_Init();		// Init MFRC522
delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
mfrc522.PCD_DumpVersionToSerial();
}

void loop() {
  //motor on
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);

  if (Serial.available() > 0){
    char box_number = Serial.read();
    if (box_number == '1'){
    digitalWrite(Piston1,LOW);
    delay(2000);
    digitalWrite(Piston2,LOW);
    delay(1000);
    digitalWrite(Piston2,HIGH);
  }
  if (box_number == '2'){
    digitalWrite(Piston1,LOW);
    delay(2000);
    digitalWrite(Piston3,LOW);
    delay(1000);
    digitalWrite(Piston3,HIGH);
  }
  if (box_number == '3'){
    digitalWrite(Piston1,HIGH);
    delay(2000);
    digitalWrite(Piston3,LOW);
    delay(1000);
    digitalWrite(Piston3,HIGH);
  }
  if (box_number == '4'){
  digitalWrite(Piston1,HIGH);
  delay(2000);
  //digitalWrite(Piston2,LOW);
  digitalWrite(Piston2,HIGH);
  delay(1000);
  digitalWrite(Piston2,LOW);
  //digitalWrite(Piston2,HIGH);
  }
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}
	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}
	// Dump debug info about the card; PICC_HaltA() is automatically called
	String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  //Serial.println();
  content.toUpperCase();
  String UID = content.substring(1);
  if (IR == 1){
    if (UID == "04 3E 95 2A EB 14 9104 3E 95 2A EB 14 91")
  {
    //digitalWrite(Piston4,LOW);
    delay(1000);
    //digitalWrite(Piston4,HIGH);
  }
  }
  }
  }
  // put your main code here, to run repeatedly:
  //above code to enter box number



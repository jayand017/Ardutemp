#include <SoftwareSerial.h>

int bluetoothTx = 2;
int bluetoothRx = 3;

float tempC;
int reading;
int tempPin = 0;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  // put your setup code here, to run once:
  analogReference(INTERNAL);
  bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(tempPin);
  tempC = reading / 9.31;
  bluetooth.println(tempC);
  delay(1000);
}

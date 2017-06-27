#include <SoftwareSerial.h>

int bluetoothTx = 2;
int bluetoothRx = 3;

float tempC;
int reading;
int tempPin = 0;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  analogReference(INTERNAL);
  
  //Setup usb serial connection to computer
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available())
  {
    char toSend = (char)bluetooth.read();
    Serial.print(toSend);
  }

  //Read from usb serial to bluetooth
  if(Serial.available())
  {
    char toSend = (char)Serial.read();
    bluetooth.print(toSend);
  }

  //call emitTemp to send temperature over bluetooth
  emitTemp();
}

void emitTemp()
{
  reading = analogRead(tempPin);
  tempC = reading / 9.31;
  bluetooth.println(tempC);
  delay(2000);
}


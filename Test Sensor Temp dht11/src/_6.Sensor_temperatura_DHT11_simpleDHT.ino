
/* teste sensor temperatura */

#include <SimpleDHT.h>

#define DHTPIN 2

SimpleDHT11 dht11;

void setup() {

  // inicializa porta serie
  Serial.begin(9600);



}


void loop() {
  // vê valores do sensor
/*
  byte temperature = 0;
  byte humidity = 0;
*/  
  float temperature = 0;
  float humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read2(DHTPIN, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err); delay(1000);
    return;
  }

  Serial.print("Sample OK: ");
  Serial.print(temperature); Serial.print(" *C, ");
  Serial.print(humidity); Serial.println(" H");

  // DHT11 sampling rate is 1HZ.
  delay(1500);

}

#include <DigiUSB.h>
#include <TinyDHT.h>

#define DHTTYPE DHT11
#define DHTPIN 2
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  pinMode(1, OUTPUT);
  DigiUSB.begin();
  dht.begin();
}

void loop()
{
  // Wait a few seconds between measurements.
  delay(2000);

  digitalWrite(1, HIGH);
  int8_t h = dht.readHumidity();
  int16_t t = dht.readTemperature(0);
  digitalWrite(1, LOW);

  if ( t != BAD_TEMP && h != BAD_HUM ) {
    DigiUSB.print(" ");
    DigiUSB.print("{\"Temperature\": ");
    DigiUSB.print(t);
    DigiUSB.print(", \"Humidity\": ");
    DigiUSB.print(h);
    DigiUSB.println("}");
    DigiUSB.delay(2000);
  }
}

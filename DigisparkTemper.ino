#include <DigiUSB.h>
#include <TinyDHT.h>

#define DHTTYPE DHT11
#define DHTPIN 2
DHT dht(DHTPIN, DHTTYPE);

unsigned long last_millis;

void setup()
{
  last_millis = millis();
  pinMode(1, OUTPUT);
  DigiUSB.begin();
  dht.begin();
}

void loop()
{
  // execute every 5 seconds
  if (millis() - last_millis < 5000)
    return;
  last_millis = millis();

  // measure temperature and humidity
  digitalWrite(1, HIGH);
  int8_t h = dht.readHumidity();
  int16_t t = dht.readTemperature(0);
  digitalWrite(1, LOW);
  if ( t == BAD_TEMP || h == BAD_HUM )
    return;

  // report to usb
  DigiUSB.print(" ");
  DigiUSB.print("{\"Temperature\": ");
  DigiUSB.print(t);
  DigiUSB.print(", \"Humidity\": ");
  DigiUSB.print(h);
  DigiUSB.println("}");
  DigiUSB.delay(2000);
}

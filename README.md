# DigisparkTemper
Minimal USB temperature and humidity sensor with Digispark

![DigisparkTemper](https://user-images.githubusercontent.com/129797/58210289-fb013b00-7d23-11e9-92a7-f201dfa1da9f.jpg)

## Parts
* Digispark
* DHT11
* Jumper wires

## Wireing
Connect 5V/GND/P02 of Dispack to DHT 11.

| Digispark | DHT11 |
| --------- | ----- |
| 5V        | VCC   |
| GND       | GND   |
| P2        | DATA  |

## Sketch
Open DigisparkTemper.ino in the Arduino IDE and program it in Digispark. The board must be "Digispark (Default - 16.5mhz)" and "TinyDHT" must be added to the library.

## Check

```bash
$ sudo pip install pyusb
$ sudo ./temper.py
{"Temperature": 22, "Humidity": 60}
```

## Credit

* [digistump/DigisparkExamplePrograms](https://github.com/digistump/DigisparkExamplePrograms)
* [adafruit/TinyDHT](https://github.com/adafruit/TinyDHT)

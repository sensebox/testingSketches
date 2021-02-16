#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "SenseBoxMCU.h"


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
Ultrasonic UltrasonicA(1, 2);
Ultrasonic UltrasonicB(3, 4);





void setup() {
  senseBoxIO.powerI2C(true);
  delay(2000);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.display();
  delay(100);
  display.clearDisplay();

}


void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.println((String("Abstand A: ") + String(UltrasonicA.getDistance())));
  display.setCursor(0, 20);
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.println((String("Abstand B: ") + String(UltrasonicB.getDistance())));
  display.display();

}

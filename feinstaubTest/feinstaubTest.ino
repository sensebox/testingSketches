#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "SenseBoxMCU.h"

float p10, p25;


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

SDS011 my_sds(Serial1);




void setup() {
  senseBoxIO.powerI2C(true);
  delay(2000);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.display();
  delay(100);
  display.clearDisplay(); Serial1.begin(9600);

}


void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.println((String("PM10: ") + String(my_sds.getPm10())));
  display.setCursor(0, 20);
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.println((String("PM25: ") + String(my_sds.getPm25())));
  display.display();

}

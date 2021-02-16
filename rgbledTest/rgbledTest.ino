#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel rgb_led_1 = Adafruit_NeoPixel(1, 1, NEO_GRB + NEO_KHZ800);






void setup() {
  rgb_led_1.begin();
  rgb_led_1.setBrightness(200);


}


void loop() {
  rgb_led_1.setPixelColor(0, rgb_led_1.Color(random(0, 255), random(0, 255), random(0, 255)));
  rgb_led_1.show();
  delay(1000);

}

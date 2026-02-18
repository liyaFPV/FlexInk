#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "config.h"

GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(CS_PIN, DC_PIN, RST_PIN, BUSY_PIN));
U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit;

void elink_init(){
display.init();
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  u8g2_for_adafruit.begin(display);
  u8g2_for_adafruit.setFont(u8g2_font_unifont_t_cyrillic);
  u8g2_for_adafruit.setForegroundColor(GxEPD_BLACK);
  u8g2_for_adafruit.setBackgroundColor(GxEPD_WHITE);
}

void setup() {
  Serial.begin(115200);
  elink_init();
  u8g2_for_adafruit.setCursor(0, 10);  // координаты уже с учётом rotation
  u8g2_for_adafruit.print("Привет, мир!");
  display.display(true);
}

void loop() {}

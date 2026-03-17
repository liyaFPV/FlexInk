#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "config.h"
#include <SPI.h>
#include "sd.h"

// инициализация дисплея через hardware SPI
GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(CS_PIN, DC_PIN, RST_PIN, BUSY_PIN));

U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit;

void elink_init() {
  // hardware SPI с кастомными пинами
  SPI.begin(CLK_PIN, -1, DIN_PIN, CS_PIN); // SCK, MISO(-1), MOSI, CS

  display.init();
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);

  u8g2_for_adafruit.begin(display);
  u8g2_for_adafruit.setFont(u8g2_font_unifont_t_cyrillic);
  u8g2_for_adafruit.setForegroundColor(GxEPD_BLACK);
  u8g2_for_adafruit.setBackgroundColor(GxEPD_WHITE);
}

void setup()
{
  Serial.begin(115200);

  SPI.begin(12, 2, 13);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  if (sd_init())
  {
    sd_info();
  }

  elink_init();

  u8g2_for_adafruit.setCursor(0,10);
  u8g2_for_adafruit.print("Привет");

  display.display(true);
}

void loop() {}
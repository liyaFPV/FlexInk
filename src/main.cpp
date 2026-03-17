#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "config.h"
#include <SPI.h>
#include "sd.h"
#include "fdb.h"
#include "menu.h"
#include "display_api.h"

void setup()
{
  Serial.begin(115200);

  SPI.begin(12, 2, 13);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  sd_init();
  elink_init();
  
  draw_bar();
  draw_menu();
  display_update();
}

void loop() {
  debug_loop();
}
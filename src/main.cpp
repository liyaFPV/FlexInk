#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "config.h"
#include <SPI.h>
#include "drivers/sd.h"
#include "drivers/display_api.h"
#include "fileread.h"

void setup(){
  Serial.begin(115200);
  setCpuFrequencyMhz(240);
  SPI.begin(12, 2, 13);
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  sd_init();
  elink_init();
  elink_update();
  elink_clear();
  elink_update();
  sd_info();
}
//7 файлов
void loop() {
  draw_bar();
  draw_files();
  elink_update();
}
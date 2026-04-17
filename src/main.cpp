#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "config.h"
#include <SPI.h>
#include "drivers/sd.h"
#include "drivers/display_api.h"

void setup(){
  Serial.begin(115200);
  setCpuFrequencyMhz(240);
  SPI.begin(12, 2, 13);
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  sd_init();
  elink_init();
  elink_update();
  delay(1000);
  elink_clear();
  elink_update();
  sd_info();
}

void loop() {
  for(int i=0; i<=8; i++){
    elink_setCursor(0, 14*i);
    elink_print(String(i));
  }
  elink_update();
}
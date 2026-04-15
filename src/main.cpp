#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "config.h"
#include <SPI.h>
#include "drivers/sd.h"
#include "drivers/display_api.h"
#include "drivers/imu.h"
void setup()
{
  Serial.begin(115200);
  setCpuFrequencyMhz(240);
  SPI.begin(12, 2, 13);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  sd_init();
  elink_init();
  imu_setup();
  display_update();
  delay(1000);
  clear_screen();
  display_update();
}

void loop() {
  display_update();
}
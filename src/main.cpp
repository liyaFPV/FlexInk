#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "config.h"
#include <SPI.h>
#include "drivers/sd.h"
#include "fdb.h"
#include "menu.h"
#include "drivers/display_api.h"
#include "drivers/imu.h"
#include "drivers/rtc.h"
#include "drivers/btn_api.h"
#include "app/app.h"

void setup()
{
  Serial.begin(115200);
  setCpuFrequencyMhz(240);
  SPI.begin(12, 2, 13);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  btn_begin();
  sd_init();
  elink_init();
  imu_setup();
  rtc_setup();
  slave_test();
  display_update();
  delay(1000);
  clear_screen();
  draw_menu();
  display_update();
}

void loop() {
  btn_tick();
  debug_loop();
  draw_menu();
  display_update();
}
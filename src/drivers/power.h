#include <Arduino.h>
#include "drivers/display_api.h"
#include "drivers/sd.h"
#include "esp_pm.h"
#include "soc/rtc_cntl_reg.h"
#include "soc/rtc.h"
#include "config.h"

bool power_tick();
void sleep();
void wakeUp();
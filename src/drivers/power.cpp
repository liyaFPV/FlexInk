#include "drivers/power.h"

bool power_tick(){

}

void sleep(){
    setCpuFrequencyMhz(80);
    elink_sleep();
    sd_end();
}

void wakeUp(){
    setCpuFrequencyMhz(240);
    elink_wakeUp();
    sd_init();
}
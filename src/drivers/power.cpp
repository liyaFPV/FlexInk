#include "drivers/power.h"

bool power_tick(){

}

void sleep(){
    elink_sleep();
    sd_end();
}

void wakeUp(){
    elink_wakeUp();
    sd_init();
}
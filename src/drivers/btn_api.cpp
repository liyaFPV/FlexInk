#include "drivers/btn_api.h"

volatile bool up_click = false;
volatile bool ok_click = false;
volatile bool down_click = false;
volatile bool return_click = false;

volatile uint32_t last_up = 0;
volatile uint32_t last_ok = 0;
volatile uint32_t last_down = 0;
volatile uint32_t last_return = 0;

const uint32_t DEBOUNCE_MS = 150;

void IRAM_ATTR btn_LOW_up_irs() {
    uint32_t now = millis();

    if (now - last_up > DEBOUNCE_MS) {
        up_click = true;
        last_up = now;
    }
}

void IRAM_ATTR btn_LOW_ok_irs() {
    uint32_t now = millis();

    if (now - last_ok > DEBOUNCE_MS) {
        ok_click = true;
        last_ok = now;
    }
}

void IRAM_ATTR btn_LOW_down_irs() {
    uint32_t now = millis();

    if (now - last_down > DEBOUNCE_MS) {
        down_click = true;
        last_down = now;
    }
}

void IRAM_ATTR btn_LOW_return_irs() {
    uint32_t now = millis();

    if (now - last_return > DEBOUNCE_MS) {
        return_click = true;
        last_return = now;
    }
}

void btn_begin() {

    pinMode(btn_up_pin, INPUT_PULLUP);
    pinMode(btn_ok_pin, INPUT_PULLUP);
    pinMode(btn_down_pin, INPUT_PULLUP);
    pinMode(btn_return_pin, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(btn_up_pin), btn_LOW_up_irs, FALLING);
    attachInterrupt(digitalPinToInterrupt(btn_ok_pin), btn_LOW_ok_irs, FALLING);
    attachInterrupt(digitalPinToInterrupt(btn_down_pin), btn_LOW_down_irs, FALLING);
    attachInterrupt(digitalPinToInterrupt(btn_return_pin), btn_LOW_return_irs, FALLING);
}

bool up_onClick() {
    if (up_click) {
        up_click = false;
        return true;
    }
    return false;
}

bool ok_onClick() {
    if (ok_click) {
        ok_click = false;
        return true;
    }
    return false;
}

bool down_onClick() {
    if (down_click) {
        down_click = false;
        return true;
    }
    return false;
}

bool return_onClick() {
    if (return_click) {
        return_click = false;
        return true;
    }
    return false;
}
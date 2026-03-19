#include "drivers/btn_api.h"

bool up_click, up_hold;
bool ok_click, ok_hold;
bool down_click, down_hold;
bool return_click, return_hold;

void btn_begin(){
    pinMode(btn_up_pin, INPUT_PULLUP);
    pinMode(btn_ok_pin, INPUT_PULLUP);
    pinMode(btn_down_pin, INPUT_PULLUP);
    pinMode(btn_return_pin, INPUT_PULLUP);
}

void btn_tick(){
    up_click = digitalRead(btn_up_pin) == LOW;
    ok_click = digitalRead(btn_ok_pin) == LOW;
    down_click = digitalRead(btn_down_pin) == LOW;
    return_click = digitalRead(btn_return_pin) == LOW;
}

bool up_onClick(){ return up_click; }
bool ok_onClick(){ return ok_click; }
bool down_onClick(){ return down_click; }
bool return_onClick(){ return return_click; }
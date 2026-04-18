#include"drivers/btn.h"

int btn_time_triger = 10;

int old_up_time,old_ok_time,old_down_time,old_return_time = 0;
bool btn_up_state,btn_ok_state,btn_down_state,btn_return_state = false;

void btn_init(){
    pinMode(btn_up_pin, INPUT_PULLUP);
    pinMode(btn_ok_pin, INPUT_PULLUP);
    pinMode(btn_down_pin, INPUT_PULLUP);
    pinMode(btn_return_pin, INPUT_PULLUP);
}

void btn_tick(){
    /*
    btn_up_state = false;
    btn_ok_state = false;
    btn_down_state = false;
    btn_return_state = false;
    */
    if(digitalRead(btn_ok_pin) == LOW and (millis() - old_ok_time) > btn_time_triger){
        btn_ok_state = true;
    }
    if(digitalRead(btn_up_pin) == LOW and (millis() - old_up_time) > btn_time_triger){
        btn_up_state = true;
    }
    if(digitalRead(btn_down_pin) == LOW and (millis() - old_down_time) > btn_time_triger){
        btn_down_state = true;
    }
    if(digitalRead(btn_return_pin) == LOW and (millis() - old_return_time) > btn_time_triger){
        btn_return_state = true;
    }

    if(digitalRead(btn_ok_pin) == HIGH){
        old_ok_time = millis();
        btn_ok_state = false;
    }

    if(digitalRead(btn_up_pin) == HIGH){
        old_up_time = millis();
        btn_up_state = false;
    }
    if(digitalRead(btn_down_pin) == HIGH){
        old_down_time = millis();
        btn_down_state = false;
    }
    if(digitalRead(btn_return_pin) == HIGH){
        old_return_time = millis();
        btn_return_state = false;
    }
}

bool btn_up(){
    return btn_up_state;
}

bool btn_ok(){
    return btn_ok_state;
}

bool btn_down(){
    return btn_down_state;
}

bool btn_return(){
    return btn_return_state;
}
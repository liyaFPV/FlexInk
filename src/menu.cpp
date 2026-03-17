#include "menu.h"

void draw_bar(){
    setCursor(0, 10);
    print("23:59");
    drawLine(0, 11, 296, 11, BLACK);
}

void draw_menu(){
    drawRect(0, 0, 296, 128, BLACK);
}
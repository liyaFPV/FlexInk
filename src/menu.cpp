#include "menu.h"

void draw_bar(){
    setCursor(0, 10);
    print("23:59");
    drawLine(0, 11, 296, 11, BLACK);
}

void draw_menu(){
    draw_bar();
    setCursor(0, 30);
    print(">");
    for (int i = 0; i < appCount; i++) {
        setCursor(10, 30 + i * 20);
        print(appName[i]);
    }
}
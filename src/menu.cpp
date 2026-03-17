#include "menu.h"

void slave_test(){
    clear_screen();
    if(get_imuStatus()){
        setCursor(0, 30);
        print("IMU Pass");
    }
    if(get_sdStatus()){
        setCursor(0, 60);   
        print("SD Pass");
    }
}

void draw_bar(){
    fillRect(0, 0, 296, 12, WHITE);
    setCursor(0, 10);
    print(rtc_getTime_HMS().c_str());
    setCursor(260, 10);
    print("100%");
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
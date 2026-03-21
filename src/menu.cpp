#include "menu.h"

int Cursor=0;

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
    fillRect(0, 0, 296, 128, WHITE);
    setCursor(0, 10);
    print(rtc_getTime_HMS().c_str());
    setCursor(260, 10);
    print("100%");
    drawLine(0, 11, 296, 11, BLACK);
}

void draw_menu() {
    if(up_onClick()){
        Cursor++;
    } else if(down_onClick()){
        Cursor--;
    } else if(ok_onClick()){
        runApp(appName[Cursor].name);
    }

    if (Cursor < 0) Cursor = appCount - 1;
    if (Cursor >= appCount) Cursor = 0;
    draw_bar();
    for (int i = 0; i < appCount; i++) {
        setCursor(10, 25 + i * 15);
        print(appName[i].name);
    }

    // рисуем курсор
    setCursor(0, 25 + Cursor * 15);
    print(">");
}
#include "drivers/rtc.h"

GyverDS3231Min rtc;

void rtc_setup(){
    Serial.println(rtc.isOK());
    if (rtc.isReset()) {
        rtc.setBuildTime();     // установить время компиляции прошивки
        // rtc.setTime(2025, 1, 30, 12, 45, 0); // установить время вручную
    }
}

String rtc_getTime_HM(){
    Datime dt = rtc.getTime();
    return String(dt.hour) + ":" + String(dt.minute);
}
String rtc_getTime_HMS(){
    Datime dt = rtc.getTime();
    return String(dt.hour) + ":" + String(dt.minute) + ":" + String(dt.second);
}

void rtc_Test(){
    Datime dt = rtc.getTime();
    Serial.println(dt.year);
    Serial.println(dt.month);
    Serial.println(dt.day);
    Serial.println(dt.hour);
    Serial.println(dt.minute);
    Serial.println(dt.second);
    Serial.println(rtc.getTime().toString());
}
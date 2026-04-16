#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "config.h"

#define BLACK GxEPD_BLACK
#define WHITE GxEPD_WHITE

void elink_init();//инициализация дисплея
void elink_setCursor(int16_t x, int16_t y);//установка курсора
void elink_print(const char* text);//печать текста
void elink_drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);//рисование линии
void elink_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);//рисование заполненного прямоугольника
void elink_drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);//рисование прямоугольника
void elink_update();//обновление дисплея
void elink_updateWindow(int16_t x, int16_t y, int16_t width, int16_t height);//обновление части дисплея (не стобильно)
void elink_clear();//очистка дисплея
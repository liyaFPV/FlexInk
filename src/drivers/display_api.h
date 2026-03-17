#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "config.h"

#define BLACK GxEPD_BLACK
#define WHITE GxEPD_WHITE

void elink_init();//инициализация дисплея
void setCursor(int16_t x, int16_t y);//установка курсора
void print(const char* text);//печать текста
void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);//рисование линии
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);//рисование заполненного прямоугольника
void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);//рисование прямоугольника
void display_update();//обновление дисплея
void display_updateWindow(int16_t x, int16_t y, int16_t width, int16_t height);//обновление части дисплея (не стобильно)
void clear_screen();//очистка дисплея
#include "fileread.h"

std::vector<String> myFiles;
std::vector<String> pages;
int cursor=0;
int old_cursor=-1;
int page=0;

void draw_bar(){
  elink_setCursor(0, 0);
  elink_print("Files on SD:");
  elink_drawLine(0, 13, 296, 13, BLACK);
}

void draw_files(){
    int y=14;
    if(old_cursor==-1){
        myFiles = listFiles("/");
    }
    elink_setCursor(0,14*(cursor+1));
    elink_print(">");
    for(int i=0; i<myFiles.size(); i++){
        elink_setCursor(9, y);
        elink_print(myFiles[i]);
        y+=14;
    }

    if(btn_up()){
        cursor--;
    }
    if(btn_down()){
        cursor++;
    }

    if(cursor<0){
        cursor = myFiles.size() - 1;
    }
    if(cursor>myFiles.size()-1){
        cursor=0;
    }
    if(old_cursor!=cursor and old_cursor==-1){
        old_cursor=cursor;
        elink_update();
    }
    if(old_cursor!=cursor){
        old_cursor=cursor;
        elink_updateWindow(0,0,12,128);
    }
}

void splitTextToPages(String text) {
  pages.clear();

  String currentPage = "";
  String word = "";
  int count = 0;

  int len = text.length();

  for (int i = 0; i < len; i++) {
    char c = text[i];

    // перенос строки НЕ считаем
    if (c == '\n') {
      currentPage += c;
      continue;
    }

    if (c == ' ' || c == '\t') {
      // добавляем слово
      if (word.length() > 0) {

        if (count + word.length() > PAGE_LIMIT) {
          // новая страница
          pages.push_back(currentPage);
          currentPage = "";
          count = 0;
        }

        currentPage += word;
        currentPage += ' ';
        count += word.length() + 1;

        word = "";
      }
    } else {
      word += c;
    }
  }

  // последнее слово
  if (word.length() > 0) {
    if (count + word.length() > PAGE_LIMIT) {
      pages.push_back(currentPage);
      currentPage = "";
      count = 0;
    }
    currentPage += word;
  }

  if (currentPage.length() > 0) {
    pages.push_back(currentPage);
  }
}
#include "fileread.h"

std::vector<String> myFiles;
std::vector<String> pages;
int cursor=0;
int old_cursor=-1;
int page=0;

void splitTextToPages(String text) {
  pages.clear();

  const int LIMIT = 37*2;

  String currentPage = "";
  String word = "";
  int lineLen = 0;

  int len = text.length();

  for (int i = 0; i < len; i++) {
    char c = text[i];

    // перенос строки
    if (c == '\n') {
      if (lineLen > 0) {
        currentPage += '\n';
        lineLen = 0;
      }
      continue;
    }

    // разделители
    if (c == ' ' || c == '\t') {
      if (word.length() > 0) {

        int needed = word.length() + (lineLen > 0 ? 1 : 0);

        // если слово не помещается — перенос строки
        if (lineLen + needed > LIMIT) {
          currentPage += '\n';
          lineLen = 0;
        }

        // добавляем пробел если не начало строки
        if (lineLen > 0) {
          currentPage += ' ';
          lineLen++;
        }

        currentPage += word;
        lineLen += word.length();

        word = "";
      }
    } else {
      word += c;
    }
  }

  // последнее слово
  if (word.length() > 0) {
    int needed = word.length() + (lineLen > 0 ? 1 : 0);

    if (lineLen + needed > LIMIT) {
      currentPage += '\n';
      lineLen = 0;
    }

    if (lineLen > 0) {
      currentPage += ' ';
      lineLen++;
    }

    currentPage += word;
  }

  // одна страница (ты сам режешь дальше)
  if (currentPage.length() > 0) {
    pages.push_back(currentPage);
  }
}

void show_page() {
  int ii = 0;
  elink_clear();
  elink_setCursor(0, ii);

  int maxPages = pages.size();   // 🔥 важно

  for (int i = 0; i < maxPages && i < 8; i++) {
    elink_setCursor(0, ii);
    elink_print(pages[i]);
    Serial.println(pages[i]);
    ii += 14;
  }

  elink_update();

  while (true) {}
}

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
    if(btn_ok()){
        Serial.println("Selected file: " + myFiles[cursor]);
        String path = myFiles[cursor];
        String content = readFile(path.c_str());
        splitTextToPages(content);
        show_page();
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
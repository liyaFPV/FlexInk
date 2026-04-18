#include "fileread.h"

std::vector<String> myFiles;
std::vector<String> pages;

void draw_bar(){
  elink_setCursor(0, 0);
  elink_print("Files on SD:");
  elink_drawLine(0, 13, 296, 13, BLACK);
}

void draw_files(){
    myFiles = listFiles("/");
    int y=14;
    elink_setCursor(0,14);
    elink_print(">");
    for(int i=0; i<myFiles.size(); i++){
        elink_setCursor(9, y);
        elink_print(myFiles[i]);
        y+=14;
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
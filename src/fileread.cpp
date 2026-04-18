#include "fileread.h"

std::vector<String> myFiles;

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
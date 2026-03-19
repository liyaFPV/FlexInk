#include "test.h"

void test(){
    clear_screen();
    setCursor(0, 10);
    print("test");
    display_update();
    while (true){
        btn_tick();
        if(return_onClick()){
            return;
        }
    }
    return;
}
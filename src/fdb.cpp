#include "fdb.h"

String cmd;

void debug_loop()
{
    while (Serial.available())
    {
        char c = Serial.read();
        
        if (c == '\n')
        {
            Serial.println();
            cmd.trim();

            if (cmd == "sd")
            {
                sd_info();
            }
            if (cmd == "reboot")
            {
                ESP.restart();
            }
            if (cmd=="info")
            {
                Serial.printf("Free heap: %u bytes\n", ESP.getFreeHeap());
                Serial.printf("SD card size: %llu MB\n", sd_get_size());
                Serial.println(FW_VERSION);
            }
            else if (cmd == "help" or cmd == "?")
            {
                Serial.println("Commands:");
                Serial.println("sd");
                Serial.println("reboot");
                Serial.println("info");
                Serial.println("help");
            }
            else
            {
                Serial.println("Unknown command");
            }

            cmd = "";
        }
        else
        {
            cmd += c;
        }
    }
}
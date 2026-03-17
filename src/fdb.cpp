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

            if (cmd == "help" || cmd == "?")
            {
                Serial.println("Commands:");
                Serial.println("help");
                Serial.println("sd");
                Serial.println("reboot");
                Serial.println("info");
                Serial.println("imu");
                Serial.println("imu_com");
                Serial.println("rtc");
            }
            else if (cmd == "info")
            {
                Serial.printf("Free heap: %u bytes\n", ESP.getFreeHeap());
                Serial.printf("SD card size: %llu MB\n", sd_get_size());
                Serial.println(FW_VERSION);
            }
            else if (cmd == "imu")
            {
                imu_test();
            }
            else if (cmd == "imu_com")
            {
                while (true)
                {
                    imu_comTest();
                }
            }
            else if (cmd == "reboot")
            {
                ESP.restart();
            }
            else if (cmd == "sd")
            {
                sd_info();
            }
            else if (cmd == "rtc")
            {
                rtc_Test();
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
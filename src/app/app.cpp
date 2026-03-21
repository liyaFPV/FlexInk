#include "app.h"
#include "test.h"

App appName[] = {
    {"test", test},
    {"test", test},
    {"тест2", test}
};
const int appCount = sizeof(appName) / sizeof(appName[0]);

void runApp(const char* name) {
    for (int i = 0; i < appCount; i++) {
        if (strcmp(appName[i].name, name) == 0) {
            appName[i].func();
            return;
        }
    }
    Serial.println("Функция не найдена");
}
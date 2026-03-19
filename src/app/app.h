#pragma once

struct App {
    const char* name;
    void (*func)();
};

extern App appName[];
extern const int appCount;

void runApp(const char* name);
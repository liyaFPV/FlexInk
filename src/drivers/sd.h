#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <FS.h>
#include <SD.h>
#include <vector>
#include "config.h"

bool sd_init();
void sd_info();
uint64_t sd_get_size();
bool get_sdStatus();
void sd_end();
std::vector<String> listFiles(const char* dirname);
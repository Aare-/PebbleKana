#pragma once
#include <pebble.h>

#define STORAGE_VIBRATIONS 1
#define STORAGE_TIME_LIMIT 2
  
int getCharCount(int i);
int getKatakana(int i, int j);
char* getRomaji(int i, int j);
char* getRowName(int i);
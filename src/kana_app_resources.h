#pragma once

#include <pebble.h>

#define STORAGE_VIBRATIONS 1
#define STORAGE_TIME_LIMIT 2
#define STORAGE_QUIZ_TYPE 3
  
//GDrawCommandImage *kana_app_resources_get_icon(int icon);
int kana_app_getCharCount(int i);
int kana_app_getKatakana(int i, int j);
char* kana_app_getRomaji(int i, int j);
char* kana_app_getRowName(int i);
#pragma once

#include <pebble.h>

#define SETTINGS_STORAGE 1
#define ALPHABET_ROW_NUM 11

extern char *kana_app_rows_names[ALPHABET_ROW_NUM];
extern char *kana_app_romaji[ALPHABET_ROW_NUM][5];
  
GDrawCommandImage *kana_app_getPDCIcon(int icon);
int kana_app_getCharCount(int i);
int kana_app_getKatakana(int i, int j);
char* kana_app_getRomaji(int i, int j);
char* kana_app_getRowName(int i);
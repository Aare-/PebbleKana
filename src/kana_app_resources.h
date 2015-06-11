#pragma once

#include <pebble.h>

#define SETTINGS_STORAGE 1
#define ALPHABET_ROW_NUM 11

extern char *kana_app_rows_names[ALPHABET_ROW_NUM];
extern char *kana_app_romaji[ALPHABET_ROW_NUM][5];
  
GDrawCommandImage *kana_app_getPDCIcon(int);

int kana_app_getCharCount(int);
int kana_app_getKatakana(int);
int kana_app_getHiragana(int);

int kana_app_getHiraganaColRow(int, int);
int kana_app_getKatakanaColRow(int, int);

char* kana_app_getRomaji(int);

char* kana_app_getRowName(int);
char** kana_app_getRow(int);
char* kana_app_getRomajiByRowAndCol(int, int);
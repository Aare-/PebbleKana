#pragma once

#include <pebble.h>

#define SETTING_VIBRATIONS 0
	#define SETTING_VIBRATIONS_YES 0
	#define SETTING_VIBRATIONS_NO 1
#define SETTING_QUIZ_MODE 1
	#define QUESTION_MODE_HIRAGANA 0
	#define QUESTION_MODE_KATAKANA 1
	#define QUESTION_MODE_RANDOM 2
#define SETTING_ROMAJI_MODE 2
	#define ROMAJI_AS_ANSWERS 0
	#define ROMAJI_AS_QUESTION 1

int kana_app_settings_get_setting(int);

void kana_app_settings_init(void);
void kana_app_settings_show(void);
void kana_app_settings_deinit(void);
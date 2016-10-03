#pragma once

typedef enum { HIRAGANA, KATAKANA } kana_app_learn_mode_type;

extern kana_app_learn_mode_type kana_app_act_learn_mode;

void kana_app_learn_init(void);
void kana_app_learn_show(void);
void kana_app_learn_deinit(void);
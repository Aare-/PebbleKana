#include <pebble.h>
#include "kana_app_resources.h"
  
static const int char_count[ALPHABET_ROW_NUM] 
  = {5, 5, 5, 5, 5, 5, 5, 3, 5, 2, 1};

static const int katakana[11][5] = 
	{{RESOURCE_ID_K_A,  RESOURCE_ID_K_I,   RESOURCE_ID_K_U,   RESOURCE_ID_K_E,  RESOURCE_ID_K_O},
   {RESOURCE_ID_K_KA, RESOURCE_ID_K_KI,  RESOURCE_ID_K_KU,  RESOURCE_ID_K_KE, RESOURCE_ID_K_KO},
   {RESOURCE_ID_K_SA, RESOURCE_ID_K_SHI, RESOURCE_ID_K_SU,  RESOURCE_ID_K_SE, RESOURCE_ID_K_SO},
   {RESOURCE_ID_K_TA, RESOURCE_ID_K_CHI, RESOURCE_ID_K_TSU, RESOURCE_ID_K_TE, RESOURCE_ID_K_TO},
   {RESOURCE_ID_K_NA, RESOURCE_ID_K_NI,  RESOURCE_ID_K_NU,  RESOURCE_ID_K_NE, RESOURCE_ID_K_NO},
   {RESOURCE_ID_K_HA, RESOURCE_ID_K_HI,  RESOURCE_ID_K_FU,  RESOURCE_ID_K_HE, RESOURCE_ID_K_HO},
   {RESOURCE_ID_K_MA, RESOURCE_ID_K_MI,  RESOURCE_ID_K_MU,  RESOURCE_ID_K_ME, RESOURCE_ID_K_MO},
   {RESOURCE_ID_K_YA, RESOURCE_ID_K_YU,  RESOURCE_ID_K_YO,  0, 0},
   {RESOURCE_ID_K_RA, RESOURCE_ID_K_RI,  RESOURCE_ID_K_RU,  RESOURCE_ID_K_RE, RESOURCE_ID_K_RO},
   {RESOURCE_ID_K_WA, RESOURCE_ID_K_WO, 0, 0, 0},
   {RESOURCE_ID_K_N, 0, 0, 0, 0}};

static const int hiragana[11][5] = 
  {{RESOURCE_ID_H_A,  RESOURCE_ID_H_I,   RESOURCE_ID_H_U,   RESOURCE_ID_H_E,  RESOURCE_ID_H_O},
   {RESOURCE_ID_H_KA, RESOURCE_ID_H_KI,  RESOURCE_ID_H_KU,  RESOURCE_ID_H_KE, RESOURCE_ID_H_KO},
   {RESOURCE_ID_H_SA, RESOURCE_ID_H_SHI, RESOURCE_ID_H_SU,  RESOURCE_ID_H_SE, RESOURCE_ID_H_SO},
   {RESOURCE_ID_H_TA, RESOURCE_ID_H_CHI, RESOURCE_ID_H_TSU, RESOURCE_ID_H_TE, RESOURCE_ID_H_TO},
   {RESOURCE_ID_H_NA, RESOURCE_ID_H_NI,  RESOURCE_ID_H_NU,  RESOURCE_ID_H_NE, RESOURCE_ID_H_NO},
   {RESOURCE_ID_H_HA, RESOURCE_ID_H_HI,  RESOURCE_ID_H_FU,  RESOURCE_ID_H_HE, RESOURCE_ID_H_HO},
   {RESOURCE_ID_H_MA, RESOURCE_ID_H_MI,  RESOURCE_ID_H_MU,  RESOURCE_ID_H_ME, RESOURCE_ID_H_MO},
   {RESOURCE_ID_H_YA, RESOURCE_ID_H_YU,  RESOURCE_ID_H_YO,  0, 0},
   {RESOURCE_ID_H_RA, RESOURCE_ID_H_RI,  RESOURCE_ID_H_RU,  RESOURCE_ID_H_RE, RESOURCE_ID_H_RO},
   {RESOURCE_ID_H_WA, RESOURCE_ID_H_WO, 0, 0, 0},
   {RESOURCE_ID_H_N, 0, 0, 0, 0}};   

char *kana_app_rows_names[ALPHABET_ROW_NUM] = 
  {
   "A-",
   "KA-",
   "SA-",
   "TA-",
   "NA-",
   "HA-",
   "MA-",
   "YA-",
   "RA-",
   "WA-",
   "N"
  };

char *kana_app_romaji[ALPHABET_ROW_NUM][5] = 
  {{"A",  "I",   "U",   "E",  "O"},
   {"KA", "KI",  "KU",  "KE", "KO"},
   {"SA", "SI",  "SU",  "SE", "SO"},
   {"TA", "CHI", "TSU", "TE", "TO"},   
   {"NA", "NI",  "NU",  "NE", "NO"},   
   {"HA", "HI",  "FU",  "HE", "HO"},
   {"MA", "MI",  "MU",  "ME", "MO"},
   {"YA", "YU",  "YO",  "",   ""},
   {"RA", "RI",  "RU",  "RE", "RO"},
   {"WA", "WE",  "WO",    "",   ""},
   {"N", "", "", "", ""}};

GDrawCommandImage *kana_app_getPDCIcon(int resourceId) {
  return gdraw_command_image_create_with_resource(resourceId);
}

int kana_app_getCharCount(int i) {
  return char_count[i];
}

int kana_app_getKatakana(int i) {
  int j = 0;
  while(i >= char_count[j]) {
    i -= char_count[j];
    j++;
  }
  return katakana[j][i];
}

int kana_app_getHiragana(int i) {
  int j = 0;
  while(i >= char_count[j]) {
    i -= char_count[j];
    j++;
  }
  return hiragana[j][i];
}

char* kana_app_getRomaji(int i) {
  int j = 0;
  while(i >= char_count[j]) {
    i -= char_count[j];
    j++;
  }
  return kana_app_romaji[j][i];
}

char* kana_app_getRowName(int i) {
  return kana_app_rows_names[i];
}  

char* kana_app_getRomajiByRowAndCol(int i, int j) {
  return kana_app_romaji[i][j];
}

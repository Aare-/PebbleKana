#include <pebble.h>
#include "common.h"
  
static const int char_count[] = {5, 5, 5, 5, 5, 5, 5, 3, 5, 2, 1};
static const int katakana[5][5] = 
	{{RESOURCE_ID_K_A, RESOURCE_ID_K_I, RESOURCE_ID_K_U, RESOURCE_ID_K_E, RESOURCE_ID_K_O},
   {RESOURCE_ID_K_KA, RESOURCE_ID_K_KI, RESOURCE_ID_K_KU, RESOURCE_ID_K_KE, RESOURCE_ID_K_KO},
   {RESOURCE_ID_K_SA, RESOURCE_ID_K_SHI, RESOURCE_ID_K_SU, RESOURCE_ID_K_SE, RESOURCE_ID_K_SO},
   {RESOURCE_ID_K_TA, RESOURCE_ID_K_CHI, RESOURCE_ID_K_TSU, RESOURCE_ID_K_TE, RESOURCE_ID_K_TO},
   {RESOURCE_ID_K_NA, RESOURCE_ID_K_NI, RESOURCE_ID_K_NU, RESOURCE_ID_K_NE, RESOURCE_ID_K_NO}};
	
static char * romaji[11][5] = 
	{{"A",  "I",   "U",   "E",  "O"},
	 {"KA", "KI",  "KU",  "KE", "KO"},
	 {"SA", "SI",  "SU",  "SE", "SO"},
	 {"TA", "CHI", "TSU", "TE", "TO"},	 
	 {"NA", "NI",  "NU",  "NE", "NO"},	 
	 {"HA", "HI",  "FU",  "HE", "HO"},
	 {"MA", "MI",  "MU",  "ME", "MO"},
	 {"YA", "YU",  "YO",  "",   ""},
	 {"RA", "RI",  "RU",  "RE", "RO"},
	 {"WA", "WO",  "",    "",   ""},
	 {"N", "", "", "", ""}};

int getCharCount(int i) {
  return char_count[i];
}

int getKatakana(int i, int j) {
  return katakana[i][j];
}

 char* getRomaji(int i, int j) {
  return romaji[i][j];
}
#include <pebble.h>
#include "common.h"
  
static const int char_count[] = {5, 5, 5, 5, 5, 5, 5, 3, 5, 2, 1};
static const int katakana[1][5] = 
	{{RESOURCE_ID_K_A, RESOURCE_ID_K_I, RESOURCE_ID_K_U, RESOURCE_ID_K_E, RESOURCE_ID_K_O}};
	
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
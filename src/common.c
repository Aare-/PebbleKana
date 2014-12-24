#include <pebble.h>
#include "common.h"
  
static const int char_count[] = {5, 5, 5, 5, 5, 5, 5, 3, 5, 2, 1};
static const int katakana[11][5] = 
	{{RESOURCE_ID_K_A, RESOURCE_ID_K_I, RESOURCE_ID_K_U, RESOURCE_ID_K_E, RESOURCE_ID_K_O},
   {RESOURCE_ID_K_KA, RESOURCE_ID_K_KI, RESOURCE_ID_K_KU, RESOURCE_ID_K_KE, RESOURCE_ID_K_KO},
   {RESOURCE_ID_K_SA, RESOURCE_ID_K_SHI, RESOURCE_ID_K_SU, RESOURCE_ID_K_SE, RESOURCE_ID_K_SO},
   {RESOURCE_ID_K_TA, RESOURCE_ID_K_CHI, RESOURCE_ID_K_TSU, RESOURCE_ID_K_TE, RESOURCE_ID_K_TO},
   {RESOURCE_ID_K_NA, RESOURCE_ID_K_NI, RESOURCE_ID_K_NU, RESOURCE_ID_K_NE, RESOURCE_ID_K_NO},
   {RESOURCE_ID_K_HA, RESOURCE_ID_K_HI, RESOURCE_ID_K_FU, RESOURCE_ID_K_HE, RESOURCE_ID_K_HO},
   {RESOURCE_ID_K_MA, RESOURCE_ID_K_MI, RESOURCE_ID_K_MU, RESOURCE_ID_K_ME, RESOURCE_ID_K_MO},
   {RESOURCE_ID_K_YA, RESOURCE_ID_K_YU, RESOURCE_ID_K_YO, 0, 0},
   {RESOURCE_ID_K_RA, RESOURCE_ID_K_RI, RESOURCE_ID_K_RU, RESOURCE_ID_K_RE, RESOURCE_ID_K_RO},
   {RESOURCE_ID_K_WA, RESOURCE_ID_K_WO, 0, 0, 0},
   {RESOURCE_ID_K_N, 0, 0, 0, 0}};
	
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

static char * rowsNames[11] = 
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

int getCharCount(int i) {
  return char_count[i];
}

int getKatakana(int i, int j) {
  return katakana[i][j];
}

char* getRowName(int i) {
  return rowsNames[i];
}  

 char* getRomaji(int i, int j) {
  return romaji[i][j];
}
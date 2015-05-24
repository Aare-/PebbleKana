#define GLYPHS_NUM 46

----------

#include <pebble.h>
#include "kana_app_glyphs.h"

Glyph kana_app_katakana_glyphs[GLYPHS_NUM];

Glyph kana_app_hiragana_glyphs[GLYPHS_NUM];

static const GPathInfo GLYPH_KANA_0_0 = 
{
    .num_points = 19,
    .points = (GPoint[]) {{0,1}, {2,14}, {99,12}, {83,31}, {66,42}, {66,30}, {52,27}, {47,67}, {34,90}, {19,101}, {28,114}, {47,94}, {61,70}, {63,46}, {72,57}, {99,36}, {112,16}, {120,10}, {105,0}}
};

static const GPathInfo GLYPH_KANA_1_0 = 
{
    .num_points = 13,
    .points = (GPoint[]) {{0,59}, {52,35}, {88,2}, {104,-22}, {120,-12}, {95,15}, {80,31}, {86,31}, {85,119}, {68,119}, {68,42}, {34,64}, {6,76}}
};

static const GPathInfo GLYPH_KANA_2_0 = 
{
    .num_points = 18,
    .points = (GPoint[]) {{11,62}, {0,62}, {-4,6}, {44,6}, {44,-23}, {62,-23}, {62,6}, {103,6}, {115,16}, {107,60}, {74,102}, {28,118}, {22,102}, {49,99}, {79,77}, {96,46}, {96,24}, {11,22}}
};

static const GPathInfo GLYPH_KANA_3_0 = 
{
    .num_points = 12,
    .points = (GPoint[]) {{13,0}, {14,12}, {50,11}, {51,67}, {-1,67}, {0,78}, {118,78}, {118,67}, {66,67}, {66,12}, {103,12}, {103,2}}
};

static const GPathInfo GLYPH_KANA_4_0 = 
{
    .num_points = 21,
    .points = (GPoint[]) {{0,86}, {7,96}, {39,71}, {64,40}, {65,92}, {62,93}, {52,90}, {46,101}, {67,106}, {78,100}, {76,31}, {120,30}, {118,19}, {78,19}, {78,-11}, {65,-9}, {66,17}, {1,17}, {1,29}, {54,30}, {28,62}}
};

static const GPathInfo GLYPH_KANA_5_0 = 
{
    .num_points = 21,
    .points = (GPoint[]) {{0,28}, {4,44}, {51,40}, {34,85}, {4,116}, {16,130}, {49,89}, {65,40}, {104,40}, {102,100}, {95,107}, {77,103}, {72,118}, {99,124}, {113,112}, {119,32}, {110,24}, {68,26}, {66,-8}, {51,-10}, {53,26}}
};

static const GPathInfo GLYPH_KANA_6_0 = 
{
    .num_points = 20,
    .points = (GPoint[]) {{33,0}, {39,23}, {-2,29}, {3,42}, {39,37}, {45,64}, {-7,71}, {-2,85}, {49,77}, {61,126}, {76,121}, {65,76}, {112,69}, {108,55}, {61,66}, {54,34}, {94,28}, {92,18}, {52,25}, {46,0}}
};

static const GPathInfo GLYPH_KANA_7_0 = 
{
    .num_points = 17,
    .points = (GPoint[]) {{31,0}, {13,40}, {-15,69}, {-5,84}, {24,60}, {32,36}, {83,34}, {68,81}, {31,117}, {-11,129}, {-3,147}, {49,120}, {80,90}, {104,31}, {91,18}, {38,18}, {47,0}}
};

static const GPathInfo GLYPH_KANA_8_0 = 
{
    .num_points = 19,
    .points = (GPoint[]) {{30,0}, {24,29}, {12,52}, {-6,71}, {4,79}, {32,44}, {66,44}, {63,71}, {50,94}, {18,108}, {24,122}, {54,107}, {71,86}, {80,55}, {80,44}, {113,42}, {113,29}, {36,30}, {45,2}}
};

static const GPathInfo GLYPH_KANA_9_0 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{0,3}, {1,17}, {102,17}, {100,85}, {1,85}, {0,100}, {102,100}, {102,108}, {120,108}, {120,-1}}
};

static const GPathInfo GLYPH_KANA_10_0 = 
{
    .num_points = 24,
    .points = (GPoint[]) {{26,7}, {26,33}, {-3,33}, {-3,44}, {25,44}, {28,74}, {38,72}, {38,46}, {71,45}, {67,75}, {55,88}, {38,95}, {43,107}, {68,93}, {80,76}, {84,45}, {116,44}, {115,33}, {86,33}, {86,0}, {71,1}, {71,31}, {38,32}, {36,4}}
};

static const GPathInfo GLYPH_KANA_11_0 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{77,0}, {59,31}, {30,54}, {1,68}, {-24,71}, {-16,90}, {23,75}, {66,46}, {95,7}}
};

static const GPathInfo GLYPH_KANA_11_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,10}, {54,35}, {98,64}, {120,28}, {69,-4}, {21,-26}}
};

static const GPathInfo GLYPH_KANA_11_2 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{6,0}, {51,17}, {104,49}, {80,88}, {34,49}, {-15,31}}
};

static const GPathInfo GLYPH_KANA_12_0 = 
{
    .num_points = 14,
    .points = (GPoint[]) {{12,0}, {16,14}, {76,10}, {63,37}, {30,69}, {-1,84}, {4,96}, {39,78}, {65,53}, {106,93}, {118,84}, {76,45}, {94,8}, {82,0}}
};

static const GPathInfo GLYPH_KANA_13_0 = 
{
    .num_points = 19,
    .points = (GPoint[]) {{29,2}, {29,31}, {-4,35}, {-2,48}, {29,43}, {29,91}, {40,103}, {104,103}, {106,91}, {47,90}, {43,85}, {43,41}, {95,34}, {70,58}, {78,68}, {115,30}, {102,20}, {42,28}, {42,0}}
};

static const GPathInfo GLYPH_KANA_14_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,7}, {75,109}, {120,87}, {40,-24}}
};

static const GPathInfo GLYPH_KANA_14_1 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{57,0}, {49,55}, {22,98}, {-15,121}, {-39,131}, {-32,148}, {20,123}, {60,81}, {80,1}}
};

static const GPathInfo GLYPH_KANA_15_0 = 
{
    .num_points = 26,
    .points = (GPoint[]) {{0,47}, {12,58}, {37,32}, {48,13}, {100,12}, {94,40}, {87,54}, {48,32}, {41,45}, {75,65}, {52,88}, {11,101}, {18,119}, {62,102}, {90,79}, {92,84}, {104,71}, {98,67}, {114,32}, {115,16}, {120,13}, {107,2}, {55,2}, {64,-17}, {44,-20}, {30,19}}
};

static const GPathInfo GLYPH_KANA_16_0 = 
{
    .num_points = 22,
    .points = (GPoint[]) {{13,19}, {17,29}, {54,22}, {54,48}, {-2,48}, {-2,58}, {52,58}, {50,77}, {39,91}, {19,100}, {26,111}, {49,99}, {64,76}, {66,56}, {117,56}, {117,44}, {66,44}, {67,19}, {63,19}, {93,8}, {87,-3}, {52,10}}
};

static const GPathInfo GLYPH_KANA_17_0 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{58,0}, {55,40}, {33,86}, {2,113}, {-38,131}, {-30,150}, {18,125}, {52,91}, {71,46}, {81,1}}
};

static const GPathInfo GLYPH_KANA_17_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{7,0}, {71,64}, {94,110}, {53,138}, {20,69}, {-25,32}}
};

static const GPathInfo GLYPH_KANA_17_2 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{8,0}, {56,48}, {92,97}, {48,128}, {12,62}, {-27,31}}
};

static const GPathInfo GLYPH_KANA_18_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,1}, {0,18}, {120,18}, {120,0}}
};

static const GPathInfo GLYPH_KANA_18_1 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {1,11}, {120,11}, {120,0}}
};

static const GPathInfo GLYPH_KANA_18_2 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{29,0}, {29,43}, {21,90}, {-9,122}, {-55,146}, {-38,178}, {31,134}, {61,73}, {64,0}}
};

static const GPathInfo GLYPH_KANA_19_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {0,1020}, {120,1020}, {120,0}}
};

static const GPathInfo GLYPH_KANA_19_1 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{7,0}, {-10,20}, {47,48}, {93,86}, {109,56}}
};

static const GPathInfo GLYPH_KANA_20_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {0,12}, {120,12}, {118,0}}
};

static const GPathInfo GLYPH_KANA_20_1 = 
{
    .num_points = 8,
    .points = (GPoint[]) {{28,3}, {31,117}, {13,201}, {-56,249}, {-41,282}, {34,228}, {64,150}, {64,-6}}
};

static const GPathInfo GLYPH_KANA_21_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {0,16}, {120,16}, {118,0}}
};

static const GPathInfo GLYPH_KANA_21_1 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {0,11}, {120,11}, {120,0}}
};

static const GPathInfo GLYPH_KANA_22_0 = 
{
    .num_points = 12,
    .points = (GPoint[]) {{10,4}, {11,20}, {91,14}, {86,37}, {58,74}, {22,100}, {-5,106}, {3,124}, {46,104}, {86,65}, {115,10}, {101,-2}}
};

static const GPathInfo GLYPH_KANA_22_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{5,0}, {-5,20}, {55,56}, {96,99}, {114,81}, {39,22}}
};

static const GPathInfo GLYPH_KANA_23_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {8,257}, {120,248}, {120,0}}
};

static const GPathInfo GLYPH_KANA_23_1 = 
{
    .num_points = 11,
    .points = (GPoint[]) {{12,3}, {12,15}, {90,15}, {72,45}, {33,68}, {-6,80}, {2,100}, {57,72}, {89,50}, {113,10}, {98,-1}}
};

static const GPathInfo GLYPH_KANA_23_2 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,11}, {10,371}, {119,371}, {119,-108}}
};

static const GPathInfo GLYPH_KANA_23_3 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{4,0}, {-10,28}, {81,91}, {109,63}}
};

static const GPathInfo GLYPH_KANA_24_0 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{64,0}, {61,39}, {42,78}, {11,104}, {-33,123}, {-22,142}, {11,124}, {49,92}, {77,44}, {86,4}}
};

static const GPathInfo GLYPH_KANA_25_0 = 
{
    .num_points = 7,
    .points = (GPoint[]) {{31,0}, {20,41}, {-19,117}, {-55,159}, {-33,178}, {20,103}, {64,11}}
};

static const GPathInfo GLYPH_KANA_25_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{9,0}, {-14,18}, {37,86}, {69,172}, {105,153}, {55,65}}
};

static const GPathInfo GLYPH_KANA_26_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{2,18}, {50,10}, {105,-12}, {118,7}, {52,23}, {-1,29}}
};

static const GPathInfo GLYPH_KANA_26_1 = 
{
    .num_points = 8,
    .points = (GPoint[]) {{0,0}, {1,112}, {16,129}, {118,129}, {120,113}, {24,113}, {16,107}, {18,0}}
};

static const GPathInfo GLYPH_KANA_27_0 = 
{
    .num_points = 13,
    .points = (GPoint[]) {{0,0}, {0,15}, {99,13}, {95,44}, {71,71}, {42,89}, {13,95}, {20,110}, {63,96}, {97,67}, {111,44}, {120,11}, {108,0}}
};

static const GPathInfo GLYPH_KANA_28_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{9,42}, {0,33}, {43,-3}, {119,50}, {108,61}, {44,10}}
};

static const GPathInfo GLYPH_KANA_29_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {0,13}, {119,13}, {118,1}}
};

static const GPathInfo GLYPH_KANA_29_1 = 
{
    .num_points = 7,
    .points = (GPoint[]) {{12,0}, {17,479}, {-37,458}, {-53,518}, {33,534}, {66,507}, {66,5}}
};

static const GPathInfo GLYPH_KANA_29_2 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{22,0}, {62,25}, {22,90}, {-21,149}, {-58,120}, {-3,61}}
};

static const GPathInfo GLYPH_KANA_29_3 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{7,0}, {-16,20}, {70,120}, {103,90}}
};

static const GPathInfo GLYPH_KANA_30_0 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{0,4}, {3,18}, {101,11}, {82,39}, {48,65}, {60,72}, {96,41}, {120,8}, {110,0}}
};

static const GPathInfo GLYPH_KANA_30_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{8,0}, {-10,23}, {51,64}, {84,101}, {109,78}, {44,25}}
};

static const GPathInfo GLYPH_KANA_31_0 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{3,0}, {-3,21}, {51,31}, {106,50}, {116,27}}
};

static const GPathInfo GLYPH_KANA_31_1 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{2,0}, {-2,23}, {57,34}, {105,50}, {117,29}}
};

static const GPathInfo GLYPH_KANA_31_2 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,0}, {19,0}, {42,2}, {69,5}, {97,7}, {120,7}}
};

static const GPathInfo GLYPH_KANA_32_0 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{41,0}, {27,55}, {13,89}, {-9,89}, {-1,107}, {41,97}, {110,86}, {104,77}, {26,86}, {59,2}}
};

static const GPathInfo GLYPH_KANA_32_1 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,7}, {49,77}, {73,145}, {120,123}, {30,-14}}
};

static const GPathInfo GLYPH_KANA_33_0 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{66,0}, {66,15}, {45,63}, {24,91}, {-33,124}, {-25,141}, {17,120}, {54,81}, {87,1}}
};

static const GPathInfo GLYPH_KANA_33_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{6,0}, {-4,15}, {55,51}, {99,88}, {115,72}, {57,26}}
};

static const GPathInfo GLYPH_KANA_34_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {0,16}, {120,14}, {120,0}}
};

static const GPathInfo GLYPH_KANA_34_1 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,1}, {0,13}, {120,12}, {120,0}}
};

static const GPathInfo GLYPH_KANA_34_2 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{0,2}, {2,131}, {13,154}, {36,161}, {113,158}, {119,135}, {34,135}, {20,128}, {23,-2}}
};

static const GPathInfo GLYPH_KANA_35_0 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{0,18}, {5,29}, {94,13}, {82,30}, {71,39}, {81,49}, {109,13}, {119,7}, {104,-2}}
};

static const GPathInfo GLYPH_KANA_35_1 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,1}, {77,353}, {120,336}, {45,-2}}
};

static const GPathInfo GLYPH_KANA_36_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,1}, {0,19}, {99,19}, {94,121}, {116,121}, {120,0}}
};

static const GPathInfo GLYPH_KANA_36_1 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,1}, {1,11}, {118,10}, {119,0}}
};

static const GPathInfo GLYPH_KANA_37_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,0}, {0,16}, {102,16}, {102,145}, {118,144}, {120,1}}
};

static const GPathInfo GLYPH_KANA_37_1 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,1}, {0,21}, {118,19}, {120,-1}}
};

static const GPathInfo GLYPH_KANA_37_2 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{66,1}, {-50,0}, {-48,18}, {69,18}}
};

static const GPathInfo GLYPH_KANA_38_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{1,1}, {-1,21}, {118,21}, {118,-1}}
};

static const GPathInfo GLYPH_KANA_38_1 = 
{
    .num_points = 11,
    .points = (GPoint[]) {{0,2}, {0,15}, {100,15}, {93,40}, {66,68}, {15,82}, {20,98}, {66,83}, {103,54}, {120,10}, {111,0}}
};

static const GPathInfo GLYPH_KANA_39_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {0,654}, {119,654}, {119,10}}
};

static const GPathInfo GLYPH_KANA_39_1 = 
{
    .num_points = 8,
    .points = (GPoint[]) {{34,0}, {32,165}, {2,216}, {-56,248}, {-46,277}, {21,237}, {58,178}, {63,2}}
};

static const GPathInfo GLYPH_KANA_40_0 = 
{
    .num_points = 7,
    .points = (GPoint[]) {{26,0}, {29,73}, {-1,169}, {-54,218}, {-26,240}, {44,147}, {66,0}}
};

static const GPathInfo GLYPH_KANA_40_1 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{4,0}, {4,156}, {-4,160}, {8,182}, {61,150}, {115,83}, {94,66}, {68,115}, {27,147}, {25,2}}
};

static const GPathInfo GLYPH_KANA_41_0 = 
{
    .num_points = 11,
    .points = (GPoint[]) {{4,1}, {4,119}, {-2,122}, {8,136}, {66,111}, {117,55}, {97,46}, {77,82}, {47,105}, {21,113}, {21,0}}
};

static const GPathInfo GLYPH_KANA_42_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {120,0}, {120,900}, {0,912}}
};

static const GPathInfo GLYPH_KANA_42_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,1}, {1,15}, {105,15}, {105,109}, {120,109}, {120,0}}
};

static const GPathInfo GLYPH_KANA_42_2 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,1}, {0,18}, {120,18}, {120,0}}
};

static const GPathInfo GLYPH_KANA_43_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{12,0}, {2,410}, {-108,420}, {-98,0}}
};

static const GPathInfo GLYPH_KANA_43_1 = 
{
    .num_points = 13,
    .points = (GPoint[]) {{0,1}, {0,16}, {101,15}, {101,42}, {83,80}, {44,102}, {27,105}, {33,121}, {72,106}, {101,81}, {117,44}, {120,11}, {114,0}}
};

static const GPathInfo GLYPH_KANA_44_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,1}, {0,16}, {120,15}, {108,0}}
};

static const GPathInfo GLYPH_KANA_44_1 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {0,16}, {112,16}, {120,0}}
};

static const GPathInfo GLYPH_KANA_44_2 = 
{
    .num_points = 8,
    .points = (GPoint[]) {{56,0}, {46,61}, {14,100}, {-42,118}, {-34,139}, {28,114}, {61,70}, {77,0}}
};

static const GPathInfo GLYPH_KANA_45_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{5,0}, {105,68}, {73,104}, {-15,44}}
};

static const GPathInfo GLYPH_KANA_45_1 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{0,59}, {6,76}, {49,63}, {85,39}, {108,11}, {120,-13}, {106,-19}, {92,9}, {64,39}, {32,57}}
};

/***************************/
/******** SEPARATOR ********/
/***************************/

static const GPathInfo GLYPH_HIRA_0_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,5}, {0,25}, {64,22}, {120,13}, {114,-3}, {46,8}}
};

static const GPathInfo GLYPH_HIRA_0_1 = 
{
    .num_points = 7,
    .points = (GPoint[]) {{2,0}, {-9,274}, {24,451}, {53,537}, {110,497}, {30,302}, {47,5}}
};

static const GPathInfo GLYPH_HIRA_0_2 = 
{
    .num_points = 24,
    .points = (GPoint[]) {{55,2}, {47,35}, {35,58}, {17,72}, {0,72}, {0,53}, {9,32}, {53,22}, {81,28}, {93,45}, {87,64}, {54,79}, {60,90}, {91,79}, {106,53}, {97,24}, {66,12}, {24,13}, {-11,38}, {-13,70}, {-2,83}, {24,80}, {44,62}, {68,0}}
};

static const GPathInfo GLYPH_HIRA_1_0 = 
{
    .num_points = 12,
    .points = (GPoint[]) {{5,0}, {39,9}, {30,132}, {46,205}, {58,211}, {83,157}, {109,173}, {87,233}, {55,255}, {33,243}, {2,173}, {-10,72}}
};

static const GPathInfo GLYPH_HIRA_1_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{10,0}, {-25,24}, {17,81}, {52,194}, {94,183}, {70,84}}
};

static const GPathInfo GLYPH_HIRA_2_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{2,0}, {-3,28}, {114,49}, {116,20}}
};

static const GPathInfo GLYPH_HIRA_2_1 = 
{
    .num_points = 14,
    .points = (GPoint[]) {{0,9}, {8,26}, {48,12}, {81,12}, {97,26}, {100,47}, {85,83}, {35,103}, {45,119}, {82,106}, {113,65}, {120,25}, {100,0}, {71,-5}}
};

static const GPathInfo GLYPH_HIRA_3_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{3,0}, {-6,29}, {113,51}, {113,19}}
};

static const GPathInfo GLYPH_HIRA_3_1 = 
{
    .num_points = 19,
    .points = (GPoint[]) {{16,4}, {19,16}, {65,11}, {-2,78}, {9,89}, {40,53}, {56,46}, {64,46}, {67,79}, {74,85}, {113,86}, {117,69}, {84,73}, {77,71}, {74,40}, {66,34}, {58,34}, {86,7}, {73,0}}
};

static const GPathInfo GLYPH_HIRA_4_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,4}, {1,23}, {72,21}, {120,15}, {114,-3}, {45,7}}
};

static const GPathInfo GLYPH_HIRA_4_1 = 
{
    .num_points = 28,
    .points = (GPoint[]) {{25,1}, {25,109}, {22,114}, {12,114}, {7,109}, {8,89}, {40,72}, {77,71}, {97,79}, {100,97}, {88,109}, {72,108}, {66,98}, {53,104}, {66,118}, {87,121}, {106,111}, {113,91}, {110,73}, {85,59}, {38,61}, {13,69}, {-6,88}, {-6,112}, {10,124}, {28,122}, {40,111}, {36,0}}
};

static const GPathInfo GLYPH_HIRA_4_2 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{4,0}, {-12,33}, {74,99}, {107,70}}
};

static const GPathInfo GLYPH_HIRA_5_0 = 
{
    .num_points = 15,
    .points = (GPoint[]) {{0,4}, {1,26}, {74,13}, {93,17}, {100,40}, {95,101}, {80,110}, {66,97}, {53,110}, {74,129}, {93,129}, {110,108}, {120,40}, {114,11}, {91,-3}}
};

static const GPathInfo GLYPH_HIRA_5_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{28,0}, {7,120}, {-56,270}, {-23,285}, {43,102}, {64,3}}
};

static const GPathInfo GLYPH_HIRA_5_2 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{8,0}, {-19,20}, {25,78}, {66,168}, {100,147}, {52,54}}
};

static const GPathInfo GLYPH_HIRA_6_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,7}, {3,25}, {81,18}, {120,8}, {114,-5}, {44,7}}
};

static const GPathInfo GLYPH_HIRA_6_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,10}, {2,23}, {84,16}, {119,10}, {114,-3}, {70,8}}
};

static const GPathInfo GLYPH_HIRA_6_2 = 
{
    .num_points = 19,
    .points = (GPoint[]) {{24,3}, {50,70}, {73,110}, {32,107}, {-2,115}, {-18,131}, {-14,158}, {5,177}, {82,183}, {85,163}, {17,163}, {2,154}, {0,133}, {24,119}, {59,119}, {87,128}, {101,115}, {61,57}, {41,-2}}
};

static const GPathInfo GLYPH_HIRA_7_0 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{43,0}, {19,43}, {-45,105}, {-43,120}, {57,221}, {74,198}, {-23,115}, {-23,105}, {39,49}, {63,14}}
};

static const GPathInfo GLYPH_HIRA_8_0 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{16,0}, {-43,0}, {-57,249}, {-25,373}, {3,387}, {62,336}, {29,300}, {3,327}, {-20,249}}
};

static const GPathInfo GLYPH_HIRA_8_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,4}, {0,22}, {90,19}, {120,15}, {112,-3}, {52,4}}
};

static const GPathInfo GLYPH_HIRA_8_2 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{22,1}, {29,198}, {15,276}, {-9,308}, {-55,325}, {-30,361}, {39,308}, {64,237}, {64,-2}}
};

static const GPathInfo GLYPH_HIRA_9_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{2,0}, {-2,23}, {44,32}, {117,32}, {117,8}, {42,10}}
};

static const GPathInfo GLYPH_HIRA_9_1 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{13,3}, {-2,-1}, {-6,16}, {-3,34}, {20,46}, {113,48}, {113,30}, {37,33}, {13,25}, {10,16}}
};

static const GPathInfo GLYPH_HIRA_10_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,9}, {2,23}, {80,17}, {120,9}, {115,-4}, {50,9}}
};

static const GPathInfo GLYPH_HIRA_10_1 = 
{
    .num_points = 19,
    .points = (GPoint[]) {{24,2}, {52,70}, {70,95}, {30,93}, {4,98}, {-16,120}, {-11,145}, {16,163}, {80,167}, {84,147}, {34,148}, {4,138}, {6,122}, {13,110}, {49,107}, {87,117}, {104,105}, {64,58}, {44,-1}}
};

static const GPathInfo GLYPH_HIRA_11_0 = 
{
    .num_points = 14,
    .points = (GPoint[]) {{16,1}, {-9,0}, {-8,15}, {-8,117}, {5,145}, {38,154}, {75,145}, {110,108}, {94,97}, {70,125}, {41,138}, {19,135}, {8,117}, {10,13}}
};

static const GPathInfo GLYPH_HIRA_12_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,2}, {2,13}, {120,10}, {118,0}}
};

static const GPathInfo GLYPH_HIRA_12_1 = 
{
    .num_points = 23,
    .points = (GPoint[]) {{26,0}, {32,132}, {26,206}, {2,215}, {-20,193}, {-20,156}, {5,147}, {32,169}, {32,246}, {-10,295}, {-41,307}, {-20,338}, {32,298}, {56,252}, {66,172}, {29,129}, {-23,129}, {-54,160}, {-54,209}, {-23,243}, {23,243}, {59,224}, {66,6}}
};

static const GPathInfo GLYPH_HIRA_13_0 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,7}, {1,18}, {120,11}, {120,0}, {46,6}}
};

static const GPathInfo GLYPH_HIRA_13_1 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{15,0}, {19,31}, {19,231}, {7,248}, {-51,235}, {-51,280}, {11,288}, {50,275}, {68,231}, {68,8}}
};

static const GPathInfo GLYPH_HIRA_13_2 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{0,0}, {3,130}, {21,154}, {71,157}, {116,155}, {120,136}, {32,136}, {19,125}, {19,1}}
};

static const GPathInfo GLYPH_HIRA_14_0 = 
{
    .num_points = 24,
    .points = (GPoint[]) {{24,5}, {27,17}, {66,13}, {22,50}, {-5,50}, {-1,62}, {65,55}, {44,74}, {41,93}, {44,107}, {57,115}, {72,118}, {96,118}, {92,104}, {68,105}, {55,100}, {53,85}, {65,65}, {86,51}, {114,49}, {108,38}, {41,44}, {91,6}, {80,-1}}
};

static const GPathInfo GLYPH_HIRA_15_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,6}, {3,27}, {61,21}, {120,13}, {114,-5}, {46,5}}
};

static const GPathInfo GLYPH_HIRA_15_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{29,0}, {-3,134}, {-55,272}, {-23,289}, {46,76}, {64,2}}
};

static const GPathInfo GLYPH_HIRA_15_2 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,0}, {5,25}, {117,25}, {120,2}, {48,0}}
};

static const GPathInfo GLYPH_HIRA_15_3 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{0,1}, {6,32}, {25,47}, {42,53}, {113,53}, {120,32}, {50,34}, {25,24}, {21,-1}}
};

static const GPathInfo GLYPH_HIRA_16_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,5}, {1,23}, {82,20}, {120,13}, {116,-3}, {62,6}}
};

static const GPathInfo GLYPH_HIRA_16_1 = 
{
    .num_points = 17,
    .points = (GPoint[]) {{12,0}, {-7,115}, {8,121}, {53,96}, {85,103}, {92,123}, {77,147}, {12,147}, {15,167}, {69,164}, {104,144}, {112,116}, {95,93}, {72,82}, {31,87}, {13,100}, {28,0}}
};

static const GPathInfo GLYPH_HIRA_17_0 = 
{
    .num_points = 17,
    .points = (GPoint[]) {{4,21}, {0,7}, {61,-3}, {92,-3}, {112,7}, {119,25}, {118,45}, {104,65}, {76,76}, {42,78}, {40,63}, {76,63}, {96,55}, {108,39}, {105,20}, {92,10}, {67,9}}
};

static const GPathInfo GLYPH_HIRA_18_0 = 
{
    .num_points = 20,
    .points = (GPoint[]) {{4,21}, {0,6}, {54,3}, {113,-4}, {119,9}, {97,9}, {70,27}, {54,52}, {54,73}, {65,86}, {84,92}, {102,91}, {99,107}, {74,105}, {53,94}, {41,73}, {41,50}, {58,25}, {71,14}, {33,17}}
};

static const GPathInfo GLYPH_HIRA_19_0 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{11,2}, {48,309}, {-19,324}, {-56,114}, {-71,-13}}
};

static const GPathInfo GLYPH_HIRA_19_1 = 
{
    .num_points = 13,
    .points = (GPoint[]) {{65,0}, {4,22}, {-28,45}, {-37,80}, {-26,102}, {23,110}, {72,107}, {76,91}, {7,94}, {-17,86}, {-21,67}, {9,41}, {82,14}}
};

static const GPathInfo GLYPH_HIRA_20_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,7}, {4,28}, {75,22}, {120,15}, {113,-8}, {51,7}}
};

static const GPathInfo GLYPH_HIRA_20_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{33,0}, {15,72}, {-55,202}, {-28,221}, {38,82}, {65,2}}
};

static const GPathInfo GLYPH_HIRA_20_2 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{3,0}, {-7,32}, {86,87}, {112,50}}
};

static const GPathInfo GLYPH_HIRA_20_3 = 
{
    .num_points = 22,
    .points = (GPoint[]) {{28,4}, {31,58}, {29,82}, {22,88}, {1,88}, {-4,79}, {-2,65}, {15,60}, {62,72}, {89,91}, {100,72}, {48,52}, {27,46}, {6,46}, {-13,53}, {-20,69}, {-20,86}, {-1,98}, {20,100}, {41,91}, {50,57}, {50,-2}}
};

static const GPathInfo GLYPH_HIRA_21_0 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{1,0}, {-3,309}, {28,415}, {51,429}, {116,383}, {84,336}, {51,369}, {51,101}, {56,0}}
};

static const GPathInfo GLYPH_HIRA_21_1 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,3}, {4,23}, {119,19}, {115,-3}}
};

static const GPathInfo GLYPH_HIRA_21_2 = 
{
    .num_points = 8,
    .points = (GPoint[]) {{0,0}, {24,0}, {28,26}, {58,40}, {120,38}, {114,62}, {52,62}, {18,48}}
};

static const GPathInfo GLYPH_HIRA_22_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{6,0}, {-34,53}, {32,106}, {86,46}}
};

static const GPathInfo GLYPH_HIRA_22_1 = 
{
    .num_points = 17,
    .points = (GPoint[]) {{48,0}, {37,81}, {23,116}, {2,145}, {-19,150}, {-25,127}, {-10,81}, {48,46}, {53,29}, {31,30}, {-21,61}, {-44,106}, {-41,160}, {-13,174}, {19,156}, {63,58}, {75,0}}
};

static const GPathInfo GLYPH_HIRA_22_2 = 
{
    .num_points = 22,
    .points = (GPoint[]) {{5,9}, {34,11}, {71,35}, {87,83}, {77,123}, {50,161}, {18,161}, {15,142}, {23,126}, {66,139}, {79,118}, {37,105}, {13,107}, {-8,129}, {-8,163}, {21,182}, {61,179}, {93,147}, {111,99}, {106,35}, {63,-4}, {5,-15}}
};

static const GPathInfo GLYPH_HIRA_22_3 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,3}, {49,120}, {93,185}, {120,162}, {60,83}, {28,-4}}
};

static const GPathInfo GLYPH_HIRA_23_0 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,0}, {0,1134}, {119,1112}, {98,349}, {119,0}}
};

static const GPathInfo GLYPH_HIRA_23_1 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,9}, {10,34}, {120,4}, {99,-13}, {40,4}}
};

static const GPathInfo GLYPH_HIRA_23_2 = 
{
    .num_points = 31,
    .points = (GPoint[]) {{32,12}, {19,38}, {-6,67}, {5,77}, {34,39}, {59,14}, {80,8}, {93,11}, {102,32}, {99,57}, {92,71}, {75,71}, {70,61}, {72,57}, {85,55}, {97,63}, {102,51}, {86,47}, {68,48}, {61,57}, {60,70}, {71,80}, {89,82}, {104,74}, {112,59}, {113,28}, {106,8}, {85,-2}, {65,3}, {37,19}, {43,7}}
};

static const GPathInfo GLYPH_HIRA_23_3 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{6,0}, {-36,56}, {27,120}, {83,56}}
};

static const GPathInfo GLYPH_HIRA_24_0 = 
{
    .num_points = 26,
    .points = (GPoint[]) {{45,12}, {42,41}, {25,73}, {12,79}, {3,64}, {13,31}, {43,9}, {72,10}, {93,24}, {95,55}, {83,77}, {52,90}, {57,102}, {93,88}, {109,64}, {110,36}, {95,10}, {57,-2}, {22,6}, {-1,31}, {-9,62}, {1,88}, {15,94}, {35,82}, {52,45}, {60,12}}
};

static const GPathInfo GLYPH_HIRA_25_0 = 
{
    .num_points = 12,
    .points = (GPoint[]) {{0,0}, {0,244}, {0,393}, {24,446}, {52,456}, {91,436}, {120,408}, {81,369}, {76,393}, {62,398}, {43,316}, {67,14}}
};

static const GPathInfo GLYPH_HIRA_25_1 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,3}, {1,19}, {120,15}, {118,-2}, {50,3}}
};

static const GPathInfo GLYPH_HIRA_25_2 = 
{
    .num_points = 22,
    .points = (GPoint[]) {{29,1}, {32,126}, {29,151}, {21,156}, {4,156}, {-5,151}, {-5,137}, {4,133}, {22,131}, {68,151}, {86,163}, {97,140}, {46,122}, {21,117}, {-3,119}, {-22,133}, {-22,156}, {-1,171}, {30,171}, {45,158}, {50,117}, {48,0}}
};

static const GPathInfo GLYPH_HIRA_26_0 = 
{
    .num_points = 23,
    .points = (GPoint[]) {{25,13}, {-1,18}, {-4,5}, {35,0}, {44,7}, {21,44}, {16,75}, {28,91}, {51,92}, {69,81}, {75,47}, {65,2}, {79,-2}, {92,26}, {115,53}, {103,65}, {86,39}, {84,80}, {69,95}, {45,105}, {15,99}, {1,77}, {7,39}}
};

static const GPathInfo GLYPH_HIRA_27_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{5,0}, {-10,27}, {53,57}, {101,69}, {110,39}, {44,21}}
};

static const GPathInfo GLYPH_HIRA_27_1 = 
{
    .num_points = 19,
    .points = (GPoint[]) {{6,0}, {1,44}, {6,57}, {60,96}, {76,122}, {73,148}, {52,156}, {21,148}, {11,135}, {-9,148}, {19,174}, {60,180}, {89,166}, {110,140}, {105,99}, {66,65}, {34,49}, {34,23}, {37,7}}
};

static const GPathInfo GLYPH_HIRA_27_2 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{26,0}, {54,21}, {-41,112}, {-65,88}}
};

static const GPathInfo GLYPH_HIRA_27_3 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{6,0}, {-15,28}, {41,88}, {69,127}, {104,95}}
};

static const GPathInfo GLYPH_HIRA_28_0 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{9,42}, {0,35}, {39,-1}, {46,-3}, {52,-1}, {86,29}, {119,54}, {109,66}, {48,11}, {42,11}}
};

static const GPathInfo GLYPH_HIRA_29_0 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{0,0}, {0,388}, {24,446}, {62,451}, {120,403}, {86,355}, {67,384}, {48,369}, {48,153}, {62,0}}
};

static const GPathInfo GLYPH_HIRA_29_1 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,2}, {0,24}, {120,20}, {120,-2}, {46,4}}
};

static const GPathInfo GLYPH_HIRA_29_2 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,4}, {0,21}, {120,14}, {118,-3}, {53,3}}
};

static const GPathInfo GLYPH_HIRA_29_3 = 
{
    .num_points = 19,
    .points = (GPoint[]) {{31,0}, {34,91}, {32,125}, {14,128}, {-2,125}, {-4,112}, {10,104}, {53,112}, {87,132}, {96,116}, {41,93}, {9,91}, {-13,97}, {-23,118}, {-16,137}, {7,146}, {34,144}, {50,127}, {48,1}}
};

static const GPathInfo GLYPH_HIRA_30_0 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,5}, {2,19}, {120,12}, {117,-2}, {38,5}}
};

static const GPathInfo GLYPH_HIRA_30_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{5,0}, {-3,12}, {17,20}, {116,17}, {116,3}, {18,8}}
};

static const GPathInfo GLYPH_HIRA_30_2 = 
{
    .num_points = 21,
    .points = (GPoint[]) {{36,0}, {37,111}, {36,134}, {22,141}, {3,139}, {0,125}, {12,115}, {40,117}, {69,127}, {91,140}, {103,125}, {59,108}, {23,102}, {3,102}, {-12,112}, {-16,133}, {0,146}, {23,150}, {44,143}, {52,118}, {52,1}}
};

static const GPathInfo GLYPH_HIRA_31_0 = 
{
    .num_points = 18,
    .points = (GPoint[]) {{48,10}, {-8,15}, {-13,-3}, {59,-8}, {78,-1}, {32,111}, {5,145}, {-25,143}, {-42,120}, {-32,88}, {15,66}, {32,66}, {26,83}, {-2,85}, {-19,101}, {-19,124}, {-2,124}, {33,58}}
};

static const GPathInfo GLYPH_HIRA_31_1 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{4,0}, {-3,18}, {47,27}, {100,56}, {116,36}, {64,12}}
};

static const GPathInfo GLYPH_HIRA_31_2 = 
{
    .num_points = 8,
    .points = (GPoint[]) {{35,0}, {15,96}, {-43,164}, {-56,172}, {-40,190}, {12,143}, {53,70}, {63,7}}
};

static const GPathInfo GLYPH_HIRA_32_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,3}, {3,23}, {75,19}, {120,14}, {116,-2}, {62,4}}
};

static const GPathInfo GLYPH_HIRA_32_1 = 
{
    .num_points = 31,
    .points = (GPoint[]) {{22,0}, {40,0}, {35,87}, {27,107}, {10,113}, {-5,106}, {-8,89}, {-4,68}, {11,60}, {30,61}, {37,73}, {33,108}, {35,124}, {51,126}, {83,126}, {97,118}, {90,86}, {104,83}, {111,121}, {102,133}, {80,140}, {40,140}, {23,132}, {18,120}, {22,89}, {23,72}, {16,71}, {4,80}, {4,97}, {20,94}, {26,57}}
};

static const GPathInfo GLYPH_HIRA_32_2 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{5,0}, {-14,30}, {39,69}, {74,108}, {105,73}}
};

static const GPathInfo GLYPH_HIRA_33_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,1}, {31,-1}, {62,98}, {120,183}, {91,209}, {25,89}}
};

static const GPathInfo GLYPH_HIRA_33_1 = 
{
    .num_points = 30,
    .points = (GPoint[]) {{57,1}, {45,50}, {26,87}, {14,99}, {6,98}, {3,80}, {12,53}, {38,37}, {56,34}, {78,38}, {91,53}, {95,70}, {88,94}, {69,104}, {54,106}, {59,118}, {84,110}, {103,92}, {108,62}, {95,33}, {73,20}, {36,20}, {3,38}, {-9,61}, {-11,88}, {-3,104}, {12,106}, {30,95}, {51,57}, {70,0}}
};

static const GPathInfo GLYPH_HIRA_34_0 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{0,2}, {0,17}, {86,22}, {120,22}, {120,-2}, {55,6}}
};

static const GPathInfo GLYPH_HIRA_34_1 = 
{
    .num_points = 13,
    .points = (GPoint[]) {{11,0}, {-8,132}, {3,166}, {46,186}, {93,175}, {111,134}, {105,93}, {91,100}, {91,143}, {71,166}, {28,162}, {10,139}, {30,7}}
};

static const GPathInfo GLYPH_HIRA_34_2 = 
{
    .num_points = 6,
    .points = (GPoint[]) {{4,0}, {-3,13}, {48,30}, {116,23}, {114,9}, {54,9}}
};

static const GPathInfo GLYPH_HIRA_35_0 = 
{
    .num_points = 16,
    .points = (GPoint[]) {{0,28}, {7,39}, {70,13}, {90,10}, {103,15}, {106,32}, {95,42}, {78,38}, {71,32}, {65,41}, {81,52}, {102,52}, {115,41}, {120,22}, {107,1}, {75,-3}}
};

static const GPathInfo GLYPH_HIRA_35_1 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{0,0}, {0,230}, {110,200}, {120,0}}
};

static const GPathInfo GLYPH_HIRA_35_2 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,6}, {86,248}, {120,238}, {46,63}, {31,-9}}
};

static const GPathInfo GLYPH_HIRA_36_0 = 
{
    .num_points = 24,
    .points = (GPoint[]) {{3,0}, {0,54}, {5,87}, {19,81}, {16,67}, {38,34}, {68,21}, {90,21}, {105,33}, {103,58}, {86,72}, {62,71}, {48,55}, {39,65}, {55,80}, {82,83}, {101,77}, {119,55}, {119,30}, {99,13}, {76,9}, {45,16}, {14,52}, {18,4}}
};

static const GPathInfo GLYPH_HIRA_36_1 = 
{
    .num_points = 8,
    .points = (GPoint[]) {{17,2}, {25,171}, {5,312}, {-53,395}, {-16,424}, {45,312}, {66,208}, {66,-6}}
};

static const GPathInfo GLYPH_HIRA_37_0 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{40,0}, {48,22}, {-68,33}, {-71,2}, {-38,5}}
};

static const GPathInfo GLYPH_HIRA_37_1 = 
{
    .num_points = 21,
    .points = (GPoint[]) {{47,0}, {48,102}, {43,124}, {27,133}, {0,133}, {-16,120}, {-16,102}, {-4,90}, {23,87}, {63,93}, {103,111}, {91,125}, {61,107}, {33,99}, {8,101}, {-2,109}, {0,120}, {21,124}, {34,117}, {39,98}, {37,0}}
};

static const GPathInfo GLYPH_HIRA_38_0 = 
{
    .num_points = 4,
    .points = (GPoint[]) {{5,0}, {-10,30}, {106,64}, {109,30}}
};

static const GPathInfo GLYPH_HIRA_38_1 = 
{
    .num_points = 18,
    .points = (GPoint[]) {{6,0}, {-3,77}, {10,79}, {33,56}, {75,47}, {96,55}, {103,77}, {83,98}, {23,102}, {25,120}, {69,116}, {101,102}, {116,74}, {114,50}, {72,32}, {35,40}, {12,53}, {18,1}}
};

static const GPathInfo GLYPH_HIRA_39_0 = 
{
    .num_points = 9,
    .points = (GPoint[]) {{2,0}, {-7,216}, {11,312}, {59,312}, {112,244}, {88,211}, {45,259}, {35,129}, {59,9}}
};

static const GPathInfo GLYPH_HIRA_39_1 = 
{
    .num_points = 10,
    .points = (GPoint[]) {{32,1}, {45,131}, {27,204}, {-20,238}, {-51,248}, {-35,277}, {22,241}, {52,204}, {68,149}, {63,-1}}
};

static const GPathInfo GLYPH_HIRA_40_0 = 
{
    .num_points = 29,
    .points = (GPoint[]) {{51,9}, {6,14}, {3,1}, {65,-3}, {76,4}, {35,51}, {67,45}, {91,54}, {103,79}, {95,106}, {61,125}, {27,123}, {17,106}, {23,86}, {43,83}, {65,98}, {67,110}, {57,114}, {52,101}, {35,95}, {27,107}, {35,115}, {73,107}, {87,95}, {87,73}, {61,55}, {22,67}, {-5,97}, {-17,85}}
};

static const GPathInfo GLYPH_HIRA_41_0 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,0}, {0,1040}, {120,1020}, {80,410}, {120,10}}
};

static const GPathInfo GLYPH_HIRA_41_1 = 
{
    .num_points = 25,
    .points = (GPoint[]) {{4,13}, {8,23}, {33,15}, {22,38}, {0,63}, {9,72}, {43,29}, {69,10}, {80,11}, {83,17}, {80,69}, {88,79}, {100,78}, {119,56}, {108,52}, {100,66}, {94,66}, {94,12}, {87,3}, {71,0}, {37,21}, {43,11}, {49,8}, {39,4}, {20,10}}
};

static const GPathInfo GLYPH_HIRA_42_0 = 
{
    .num_points = 21,
    .points = (GPoint[]) {{12,4}, {17,16}, {63,9}, {-4,86}, {4,97}, {29,72}, {64,57}, {93,66}, {100,85}, {96,107}, {74,117}, {31,115}, {35,130}, {74,130}, {104,119}, {115,89}, {103,60}, {78,48}, {46,53}, {86,6}, {72,-1}}
};

static const GPathInfo GLYPH_HIRA_43_0 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,0}, {0,1040}, {120,1010}, {100,390}, {110,30}}
};

static const GPathInfo GLYPH_HIRA_43_1 = 
{
    .num_points = 24,
    .points = (GPoint[]) {{5,8}, {9,18}, {32,13}, {30,32}, {0,66}, {8,75}, {24,53}, {48,32}, {65,20}, {87,18}, {99,22}, {106,38}, {103,61}, {89,72}, {67,76}, {72,88}, {101,77}, {117,59}, {119,30}, {99,9}, {75,7}, {39,20}, {50,7}, {41,-1}}
};

static const GPathInfo GLYPH_HIRA_44_0 = 
{
    .num_points = 5,
    .points = (GPoint[]) {{0,7}, {7,24}, {120,10}, {118,-5}, {44,7}}
};

static const GPathInfo GLYPH_HIRA_44_1 = 
{
    .num_points = 14,
    .points = (GPoint[]) {{38,0}, {4,70}, {-43,122}, {-24,137}, {-4,109}, {34,94}, {55,98}, {57,171}, {76,169}, {76,107}, {61,83}, {42,79}, {11,85}, {57,4}}
};

static const GPathInfo GLYPH_HIRA_44_2 = 
{
    .num_points = 14,
    .points = (GPoint[]) {{68,0}, {0,34}, {-27,54}, {-35,69}, {-30,86}, {-9,97}, {64,97}, {68,82}, {15,85}, {-10,80}, {-15,68}, {-1,51}, {37,30}, {84,13}}
};

static const GPathInfo GLYPH_HIRA_45_0 = 
{
    .num_points = 23,
    .points = (GPoint[]) {{46,0}, {20,57}, {-6,103}, {5,109}, {24,75}, {40,64}, {48,60}, {53,64}, {56,93}, {60,105}, {68,109}, {89,106}, {113,67}, {101,58}, {91,87}, {83,96}, {74,96}, {68,84}, {65,56}, {59,49}, {50,49}, {32,57}, {59,3}}
};

void kana_app_glyphs_init() 
{
kana_app_katakana_glyphs[0].size = 1;
kana_app_katakana_glyphs[0].glyph_path[0] = &GLYPH_KANA_0_0;

kana_app_katakana_glyphs[1].size = 1;
kana_app_katakana_glyphs[1].glyph_path[0] = &GLYPH_KANA_1_0;

kana_app_katakana_glyphs[2].size = 1;
kana_app_katakana_glyphs[2].glyph_path[0] = &GLYPH_KANA_2_0;

kana_app_katakana_glyphs[3].size = 1;
kana_app_katakana_glyphs[3].glyph_path[0] = &GLYPH_KANA_3_0;

kana_app_katakana_glyphs[4].size = 1;
kana_app_katakana_glyphs[4].glyph_path[0] = &GLYPH_KANA_4_0;

kana_app_katakana_glyphs[5].size = 1;
kana_app_katakana_glyphs[5].glyph_path[0] = &GLYPH_KANA_5_0;

kana_app_katakana_glyphs[6].size = 1;
kana_app_katakana_glyphs[6].glyph_path[0] = &GLYPH_KANA_6_0;

kana_app_katakana_glyphs[7].size = 1;
kana_app_katakana_glyphs[7].glyph_path[0] = &GLYPH_KANA_7_0;

kana_app_katakana_glyphs[8].size = 1;
kana_app_katakana_glyphs[8].glyph_path[0] = &GLYPH_KANA_8_0;

kana_app_katakana_glyphs[9].size = 1;
kana_app_katakana_glyphs[9].glyph_path[0] = &GLYPH_KANA_9_0;

kana_app_katakana_glyphs[10].size = 1;
kana_app_katakana_glyphs[10].glyph_path[0] = &GLYPH_KANA_10_0;

kana_app_katakana_glyphs[11].size = 3;
kana_app_katakana_glyphs[11].glyph_path[0] = &GLYPH_KANA_11_0;
kana_app_katakana_glyphs[11].glyph_path[1] = &GLYPH_KANA_11_1;
kana_app_katakana_glyphs[11].glyph_path[2] = &GLYPH_KANA_11_2;

kana_app_katakana_glyphs[12].size = 1;
kana_app_katakana_glyphs[12].glyph_path[0] = &GLYPH_KANA_12_0;

kana_app_katakana_glyphs[13].size = 1;
kana_app_katakana_glyphs[13].glyph_path[0] = &GLYPH_KANA_13_0;

kana_app_katakana_glyphs[14].size = 2;
kana_app_katakana_glyphs[14].glyph_path[0] = &GLYPH_KANA_14_0;
kana_app_katakana_glyphs[14].glyph_path[1] = &GLYPH_KANA_14_1;

kana_app_katakana_glyphs[15].size = 1;
kana_app_katakana_glyphs[15].glyph_path[0] = &GLYPH_KANA_15_0;

kana_app_katakana_glyphs[16].size = 1;
kana_app_katakana_glyphs[16].glyph_path[0] = &GLYPH_KANA_16_0;

kana_app_katakana_glyphs[17].size = 3;
kana_app_katakana_glyphs[17].glyph_path[0] = &GLYPH_KANA_17_0;
kana_app_katakana_glyphs[17].glyph_path[1] = &GLYPH_KANA_17_1;
kana_app_katakana_glyphs[17].glyph_path[2] = &GLYPH_KANA_17_2;

kana_app_katakana_glyphs[18].size = 3;
kana_app_katakana_glyphs[18].glyph_path[0] = &GLYPH_KANA_18_0;
kana_app_katakana_glyphs[18].glyph_path[1] = &GLYPH_KANA_18_1;
kana_app_katakana_glyphs[18].glyph_path[2] = &GLYPH_KANA_18_2;

kana_app_katakana_glyphs[19].size = 2;
kana_app_katakana_glyphs[19].glyph_path[0] = &GLYPH_KANA_19_0;
kana_app_katakana_glyphs[19].glyph_path[1] = &GLYPH_KANA_19_1;

kana_app_katakana_glyphs[20].size = 2;
kana_app_katakana_glyphs[20].glyph_path[0] = &GLYPH_KANA_20_0;
kana_app_katakana_glyphs[20].glyph_path[1] = &GLYPH_KANA_20_1;

kana_app_katakana_glyphs[21].size = 2;
kana_app_katakana_glyphs[21].glyph_path[0] = &GLYPH_KANA_21_0;
kana_app_katakana_glyphs[21].glyph_path[1] = &GLYPH_KANA_21_1;

kana_app_katakana_glyphs[22].size = 2;
kana_app_katakana_glyphs[22].glyph_path[0] = &GLYPH_KANA_22_0;
kana_app_katakana_glyphs[22].glyph_path[1] = &GLYPH_KANA_22_1;

kana_app_katakana_glyphs[23].size = 4;
kana_app_katakana_glyphs[23].glyph_path[0] = &GLYPH_KANA_23_0;
kana_app_katakana_glyphs[23].glyph_path[1] = &GLYPH_KANA_23_1;
kana_app_katakana_glyphs[23].glyph_path[2] = &GLYPH_KANA_23_2;
kana_app_katakana_glyphs[23].glyph_path[3] = &GLYPH_KANA_23_3;

kana_app_katakana_glyphs[24].size = 1;
kana_app_katakana_glyphs[24].glyph_path[0] = &GLYPH_KANA_24_0;

kana_app_katakana_glyphs[25].size = 2;
kana_app_katakana_glyphs[25].glyph_path[0] = &GLYPH_KANA_25_0;
kana_app_katakana_glyphs[25].glyph_path[1] = &GLYPH_KANA_25_1;

kana_app_katakana_glyphs[26].size = 2;
kana_app_katakana_glyphs[26].glyph_path[0] = &GLYPH_KANA_26_0;
kana_app_katakana_glyphs[26].glyph_path[1] = &GLYPH_KANA_26_1;

kana_app_katakana_glyphs[27].size = 1;
kana_app_katakana_glyphs[27].glyph_path[0] = &GLYPH_KANA_27_0;

kana_app_katakana_glyphs[28].size = 1;
kana_app_katakana_glyphs[28].glyph_path[0] = &GLYPH_KANA_28_0;

kana_app_katakana_glyphs[29].size = 4;
kana_app_katakana_glyphs[29].glyph_path[0] = &GLYPH_KANA_29_0;
kana_app_katakana_glyphs[29].glyph_path[1] = &GLYPH_KANA_29_1;
kana_app_katakana_glyphs[29].glyph_path[2] = &GLYPH_KANA_29_2;
kana_app_katakana_glyphs[29].glyph_path[3] = &GLYPH_KANA_29_3;

kana_app_katakana_glyphs[30].size = 2;
kana_app_katakana_glyphs[30].glyph_path[0] = &GLYPH_KANA_30_0;
kana_app_katakana_glyphs[30].glyph_path[1] = &GLYPH_KANA_30_1;

kana_app_katakana_glyphs[31].size = 3;
kana_app_katakana_glyphs[31].glyph_path[0] = &GLYPH_KANA_31_0;
kana_app_katakana_glyphs[31].glyph_path[1] = &GLYPH_KANA_31_1;
kana_app_katakana_glyphs[31].glyph_path[2] = &GLYPH_KANA_31_2;

kana_app_katakana_glyphs[32].size = 2;
kana_app_katakana_glyphs[32].glyph_path[0] = &GLYPH_KANA_32_0;
kana_app_katakana_glyphs[32].glyph_path[1] = &GLYPH_KANA_32_1;

kana_app_katakana_glyphs[33].size = 2;
kana_app_katakana_glyphs[33].glyph_path[0] = &GLYPH_KANA_33_0;
kana_app_katakana_glyphs[33].glyph_path[1] = &GLYPH_KANA_33_1;

kana_app_katakana_glyphs[34].size = 3;
kana_app_katakana_glyphs[34].glyph_path[0] = &GLYPH_KANA_34_0;
kana_app_katakana_glyphs[34].glyph_path[1] = &GLYPH_KANA_34_1;
kana_app_katakana_glyphs[34].glyph_path[2] = &GLYPH_KANA_34_2;

kana_app_katakana_glyphs[35].size = 2;
kana_app_katakana_glyphs[35].glyph_path[0] = &GLYPH_KANA_35_0;
kana_app_katakana_glyphs[35].glyph_path[1] = &GLYPH_KANA_35_1;

kana_app_katakana_glyphs[36].size = 2;
kana_app_katakana_glyphs[36].glyph_path[0] = &GLYPH_KANA_36_0;
kana_app_katakana_glyphs[36].glyph_path[1] = &GLYPH_KANA_36_1;

kana_app_katakana_glyphs[37].size = 3;
kana_app_katakana_glyphs[37].glyph_path[0] = &GLYPH_KANA_37_0;
kana_app_katakana_glyphs[37].glyph_path[1] = &GLYPH_KANA_37_1;
kana_app_katakana_glyphs[37].glyph_path[2] = &GLYPH_KANA_37_2;

kana_app_katakana_glyphs[38].size = 2;
kana_app_katakana_glyphs[38].glyph_path[0] = &GLYPH_KANA_38_0;
kana_app_katakana_glyphs[38].glyph_path[1] = &GLYPH_KANA_38_1;

kana_app_katakana_glyphs[39].size = 2;
kana_app_katakana_glyphs[39].glyph_path[0] = &GLYPH_KANA_39_0;
kana_app_katakana_glyphs[39].glyph_path[1] = &GLYPH_KANA_39_1;

kana_app_katakana_glyphs[40].size = 2;
kana_app_katakana_glyphs[40].glyph_path[0] = &GLYPH_KANA_40_0;
kana_app_katakana_glyphs[40].glyph_path[1] = &GLYPH_KANA_40_1;

kana_app_katakana_glyphs[41].size = 1;
kana_app_katakana_glyphs[41].glyph_path[0] = &GLYPH_KANA_41_0;

kana_app_katakana_glyphs[42].size = 3;
kana_app_katakana_glyphs[42].glyph_path[0] = &GLYPH_KANA_42_0;
kana_app_katakana_glyphs[42].glyph_path[1] = &GLYPH_KANA_42_1;
kana_app_katakana_glyphs[42].glyph_path[2] = &GLYPH_KANA_42_2;

kana_app_katakana_glyphs[43].size = 2;
kana_app_katakana_glyphs[43].glyph_path[0] = &GLYPH_KANA_43_0;
kana_app_katakana_glyphs[43].glyph_path[1] = &GLYPH_KANA_43_1;

kana_app_katakana_glyphs[44].size = 3;
kana_app_katakana_glyphs[44].glyph_path[0] = &GLYPH_KANA_44_0;
kana_app_katakana_glyphs[44].glyph_path[1] = &GLYPH_KANA_44_1;
kana_app_katakana_glyphs[44].glyph_path[2] = &GLYPH_KANA_44_2;

kana_app_katakana_glyphs[45].size = 2;
kana_app_katakana_glyphs[45].glyph_path[0] = &GLYPH_KANA_45_0;
kana_app_katakana_glyphs[45].glyph_path[1] = &GLYPH_KANA_45_1;

/***************************/
/******** SEPARATOR ********/
/***************************/

kana_app_hiragana_glyphs[0].size = 3;
kana_app_hiragana_glyphs[0].glyph_path[0] = &GLYPH_HIRA_0_0;
kana_app_hiragana_glyphs[0].glyph_path[1] = &GLYPH_HIRA_0_1;
kana_app_hiragana_glyphs[0].glyph_path[2] = &GLYPH_HIRA_0_2;

kana_app_hiragana_glyphs[1].size = 2;
kana_app_hiragana_glyphs[1].glyph_path[0] = &GLYPH_HIRA_1_0;
kana_app_hiragana_glyphs[1].glyph_path[1] = &GLYPH_HIRA_1_1;

kana_app_hiragana_glyphs[2].size = 2;
kana_app_hiragana_glyphs[2].glyph_path[0] = &GLYPH_HIRA_2_0;
kana_app_hiragana_glyphs[2].glyph_path[1] = &GLYPH_HIRA_2_1;

kana_app_hiragana_glyphs[3].size = 2;
kana_app_hiragana_glyphs[3].glyph_path[0] = &GLYPH_HIRA_3_0;
kana_app_hiragana_glyphs[3].glyph_path[1] = &GLYPH_HIRA_3_1;

kana_app_hiragana_glyphs[4].size = 3;
kana_app_hiragana_glyphs[4].glyph_path[0] = &GLYPH_HIRA_4_0;
kana_app_hiragana_glyphs[4].glyph_path[1] = &GLYPH_HIRA_4_1;
kana_app_hiragana_glyphs[4].glyph_path[2] = &GLYPH_HIRA_4_2;

kana_app_hiragana_glyphs[5].size = 3;
kana_app_hiragana_glyphs[5].glyph_path[0] = &GLYPH_HIRA_5_0;
kana_app_hiragana_glyphs[5].glyph_path[1] = &GLYPH_HIRA_5_1;
kana_app_hiragana_glyphs[5].glyph_path[2] = &GLYPH_HIRA_5_2;

kana_app_hiragana_glyphs[6].size = 3;
kana_app_hiragana_glyphs[6].glyph_path[0] = &GLYPH_HIRA_6_0;
kana_app_hiragana_glyphs[6].glyph_path[1] = &GLYPH_HIRA_6_1;
kana_app_hiragana_glyphs[6].glyph_path[2] = &GLYPH_HIRA_6_2;

kana_app_hiragana_glyphs[7].size = 1;
kana_app_hiragana_glyphs[7].glyph_path[0] = &GLYPH_HIRA_7_0;

kana_app_hiragana_glyphs[8].size = 3;
kana_app_hiragana_glyphs[8].glyph_path[0] = &GLYPH_HIRA_8_0;
kana_app_hiragana_glyphs[8].glyph_path[1] = &GLYPH_HIRA_8_1;
kana_app_hiragana_glyphs[8].glyph_path[2] = &GLYPH_HIRA_8_2;

kana_app_hiragana_glyphs[9].size = 2;
kana_app_hiragana_glyphs[9].glyph_path[0] = &GLYPH_HIRA_9_0;
kana_app_hiragana_glyphs[9].glyph_path[1] = &GLYPH_HIRA_9_1;

kana_app_hiragana_glyphs[10].size = 2;
kana_app_hiragana_glyphs[10].glyph_path[0] = &GLYPH_HIRA_10_0;
kana_app_hiragana_glyphs[10].glyph_path[1] = &GLYPH_HIRA_10_1;

kana_app_hiragana_glyphs[11].size = 1;
kana_app_hiragana_glyphs[11].glyph_path[0] = &GLYPH_HIRA_11_0;

kana_app_hiragana_glyphs[12].size = 2;
kana_app_hiragana_glyphs[12].glyph_path[0] = &GLYPH_HIRA_12_0;
kana_app_hiragana_glyphs[12].glyph_path[1] = &GLYPH_HIRA_12_1;

kana_app_hiragana_glyphs[13].size = 3;
kana_app_hiragana_glyphs[13].glyph_path[0] = &GLYPH_HIRA_13_0;
kana_app_hiragana_glyphs[13].glyph_path[1] = &GLYPH_HIRA_13_1;
kana_app_hiragana_glyphs[13].glyph_path[2] = &GLYPH_HIRA_13_2;

kana_app_hiragana_glyphs[14].size = 1;
kana_app_hiragana_glyphs[14].glyph_path[0] = &GLYPH_HIRA_14_0;

kana_app_hiragana_glyphs[15].size = 4;
kana_app_hiragana_glyphs[15].glyph_path[0] = &GLYPH_HIRA_15_0;
kana_app_hiragana_glyphs[15].glyph_path[1] = &GLYPH_HIRA_15_1;
kana_app_hiragana_glyphs[15].glyph_path[2] = &GLYPH_HIRA_15_2;
kana_app_hiragana_glyphs[15].glyph_path[3] = &GLYPH_HIRA_15_3;

kana_app_hiragana_glyphs[16].size = 2;
kana_app_hiragana_glyphs[16].glyph_path[0] = &GLYPH_HIRA_16_0;
kana_app_hiragana_glyphs[16].glyph_path[1] = &GLYPH_HIRA_16_1;

kana_app_hiragana_glyphs[17].size = 1;
kana_app_hiragana_glyphs[17].glyph_path[0] = &GLYPH_HIRA_17_0;

kana_app_hiragana_glyphs[18].size = 1;
kana_app_hiragana_glyphs[18].glyph_path[0] = &GLYPH_HIRA_18_0;

kana_app_hiragana_glyphs[19].size = 2;
kana_app_hiragana_glyphs[19].glyph_path[0] = &GLYPH_HIRA_19_0;
kana_app_hiragana_glyphs[19].glyph_path[1] = &GLYPH_HIRA_19_1;

kana_app_hiragana_glyphs[20].size = 4;
kana_app_hiragana_glyphs[20].glyph_path[0] = &GLYPH_HIRA_20_0;
kana_app_hiragana_glyphs[20].glyph_path[1] = &GLYPH_HIRA_20_1;
kana_app_hiragana_glyphs[20].glyph_path[2] = &GLYPH_HIRA_20_2;
kana_app_hiragana_glyphs[20].glyph_path[3] = &GLYPH_HIRA_20_3;

kana_app_hiragana_glyphs[21].size = 3;
kana_app_hiragana_glyphs[21].glyph_path[0] = &GLYPH_HIRA_21_0;
kana_app_hiragana_glyphs[21].glyph_path[1] = &GLYPH_HIRA_21_1;
kana_app_hiragana_glyphs[21].glyph_path[2] = &GLYPH_HIRA_21_2;

kana_app_hiragana_glyphs[22].size = 4;
kana_app_hiragana_glyphs[22].glyph_path[0] = &GLYPH_HIRA_22_0;
kana_app_hiragana_glyphs[22].glyph_path[1] = &GLYPH_HIRA_22_1;
kana_app_hiragana_glyphs[22].glyph_path[2] = &GLYPH_HIRA_22_2;
kana_app_hiragana_glyphs[22].glyph_path[3] = &GLYPH_HIRA_22_3;

kana_app_hiragana_glyphs[23].size = 4;
kana_app_hiragana_glyphs[23].glyph_path[0] = &GLYPH_HIRA_23_0;
kana_app_hiragana_glyphs[23].glyph_path[1] = &GLYPH_HIRA_23_1;
kana_app_hiragana_glyphs[23].glyph_path[2] = &GLYPH_HIRA_23_2;
kana_app_hiragana_glyphs[23].glyph_path[3] = &GLYPH_HIRA_23_3;

kana_app_hiragana_glyphs[24].size = 1;
kana_app_hiragana_glyphs[24].glyph_path[0] = &GLYPH_HIRA_24_0;

kana_app_hiragana_glyphs[25].size = 3;
kana_app_hiragana_glyphs[25].glyph_path[0] = &GLYPH_HIRA_25_0;
kana_app_hiragana_glyphs[25].glyph_path[1] = &GLYPH_HIRA_25_1;
kana_app_hiragana_glyphs[25].glyph_path[2] = &GLYPH_HIRA_25_2;

kana_app_hiragana_glyphs[26].size = 1;
kana_app_hiragana_glyphs[26].glyph_path[0] = &GLYPH_HIRA_26_0;

kana_app_hiragana_glyphs[27].size = 4;
kana_app_hiragana_glyphs[27].glyph_path[0] = &GLYPH_HIRA_27_0;
kana_app_hiragana_glyphs[27].glyph_path[1] = &GLYPH_HIRA_27_1;
kana_app_hiragana_glyphs[27].glyph_path[2] = &GLYPH_HIRA_27_2;
kana_app_hiragana_glyphs[27].glyph_path[3] = &GLYPH_HIRA_27_3;

kana_app_hiragana_glyphs[28].size = 1;
kana_app_hiragana_glyphs[28].glyph_path[0] = &GLYPH_HIRA_28_0;

kana_app_hiragana_glyphs[29].size = 4;
kana_app_hiragana_glyphs[29].glyph_path[0] = &GLYPH_HIRA_29_0;
kana_app_hiragana_glyphs[29].glyph_path[1] = &GLYPH_HIRA_29_1;
kana_app_hiragana_glyphs[29].glyph_path[2] = &GLYPH_HIRA_29_2;
kana_app_hiragana_glyphs[29].glyph_path[3] = &GLYPH_HIRA_29_3;

kana_app_hiragana_glyphs[30].size = 3;
kana_app_hiragana_glyphs[30].glyph_path[0] = &GLYPH_HIRA_30_0;
kana_app_hiragana_glyphs[30].glyph_path[1] = &GLYPH_HIRA_30_1;
kana_app_hiragana_glyphs[30].glyph_path[2] = &GLYPH_HIRA_30_2;

kana_app_hiragana_glyphs[31].size = 3;
kana_app_hiragana_glyphs[31].glyph_path[0] = &GLYPH_HIRA_31_0;
kana_app_hiragana_glyphs[31].glyph_path[1] = &GLYPH_HIRA_31_1;
kana_app_hiragana_glyphs[31].glyph_path[2] = &GLYPH_HIRA_31_2;

kana_app_hiragana_glyphs[32].size = 3;
kana_app_hiragana_glyphs[32].glyph_path[0] = &GLYPH_HIRA_32_0;
kana_app_hiragana_glyphs[32].glyph_path[1] = &GLYPH_HIRA_32_1;
kana_app_hiragana_glyphs[32].glyph_path[2] = &GLYPH_HIRA_32_2;

kana_app_hiragana_glyphs[33].size = 2;
kana_app_hiragana_glyphs[33].glyph_path[0] = &GLYPH_HIRA_33_0;
kana_app_hiragana_glyphs[33].glyph_path[1] = &GLYPH_HIRA_33_1;

kana_app_hiragana_glyphs[34].size = 3;
kana_app_hiragana_glyphs[34].glyph_path[0] = &GLYPH_HIRA_34_0;
kana_app_hiragana_glyphs[34].glyph_path[1] = &GLYPH_HIRA_34_1;
kana_app_hiragana_glyphs[34].glyph_path[2] = &GLYPH_HIRA_34_2;

kana_app_hiragana_glyphs[35].size = 3;
kana_app_hiragana_glyphs[35].glyph_path[0] = &GLYPH_HIRA_35_0;
kana_app_hiragana_glyphs[35].glyph_path[1] = &GLYPH_HIRA_35_1;
kana_app_hiragana_glyphs[35].glyph_path[2] = &GLYPH_HIRA_35_2;

kana_app_hiragana_glyphs[36].size = 2;
kana_app_hiragana_glyphs[36].glyph_path[0] = &GLYPH_HIRA_36_0;
kana_app_hiragana_glyphs[36].glyph_path[1] = &GLYPH_HIRA_36_1;

kana_app_hiragana_glyphs[37].size = 2;
kana_app_hiragana_glyphs[37].glyph_path[0] = &GLYPH_HIRA_37_0;
kana_app_hiragana_glyphs[37].glyph_path[1] = &GLYPH_HIRA_37_1;

kana_app_hiragana_glyphs[38].size = 2;
kana_app_hiragana_glyphs[38].glyph_path[0] = &GLYPH_HIRA_38_0;
kana_app_hiragana_glyphs[38].glyph_path[1] = &GLYPH_HIRA_38_1;

kana_app_hiragana_glyphs[39].size = 2;
kana_app_hiragana_glyphs[39].glyph_path[0] = &GLYPH_HIRA_39_0;
kana_app_hiragana_glyphs[39].glyph_path[1] = &GLYPH_HIRA_39_1;

kana_app_hiragana_glyphs[40].size = 1;
kana_app_hiragana_glyphs[40].glyph_path[0] = &GLYPH_HIRA_40_0;

kana_app_hiragana_glyphs[41].size = 2;
kana_app_hiragana_glyphs[41].glyph_path[0] = &GLYPH_HIRA_41_0;
kana_app_hiragana_glyphs[41].glyph_path[1] = &GLYPH_HIRA_41_1;

kana_app_hiragana_glyphs[42].size = 1;
kana_app_hiragana_glyphs[42].glyph_path[0] = &GLYPH_HIRA_42_0;

kana_app_hiragana_glyphs[43].size = 2;
kana_app_hiragana_glyphs[43].glyph_path[0] = &GLYPH_HIRA_43_0;
kana_app_hiragana_glyphs[43].glyph_path[1] = &GLYPH_HIRA_43_1;

kana_app_hiragana_glyphs[44].size = 3;
kana_app_hiragana_glyphs[44].glyph_path[0] = &GLYPH_HIRA_44_0;
kana_app_hiragana_glyphs[44].glyph_path[1] = &GLYPH_HIRA_44_1;
kana_app_hiragana_glyphs[44].glyph_path[2] = &GLYPH_HIRA_44_2;

kana_app_hiragana_glyphs[45].size = 1;
kana_app_hiragana_glyphs[45].glyph_path[0] = &GLYPH_HIRA_45_0;

}

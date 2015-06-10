#pragma once

#define GLYPHS_NUM 46
#define MAX_GLYPH_SEGMENTS 4

typedef struct Glyphs {
  int size;
  const GPathInfo *glyph_path[MAX_GLYPH_SEGMENTS];
} Glyph;

extern Glyph kana_app_katakana_glyphs[GLYPHS_NUM];
extern Glyph kana_app_hiragana_glyphs[GLYPHS_NUM];

void kana_app_glyphs_init(void);
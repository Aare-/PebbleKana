#include <pebble.h>
#include "kana_app_learn.h"
#include "kana_app_glyphs.h"
#include "kana_app_resources.h"
#include "kana_app_simple_menu_color.h"

#ifdef PBL_COLOR
extern GColor kana_app_bitmap_pallete[2];
#endif

static struct LearnUi {
  Window* window;
  SimpleColorMenuLayer* menu;
} ui;

static struct RowDetailsUi {
  Window* window;
  SimpleColorMenuLayer* menu;
} details_ui;

static int selectedIndex;

static GBitmap* icons[5];

static void menu_callback_click(MenuLayer* layer, MenuIndex* index, void* data) {
  selectedIndex = index->row;
  window_stack_push(details_ui.window, true);  
}

static void top_list_load(Window* window) {
  ui.menu = kana_app_simple_menu_init(
    ui.window,
    kana_app_act_learn_mode == HIRAGANA ? "Hiragana" : "Katakana",
    ALPHABET_ROW_NUM,
    kana_app_rows_names,
    NULL, NULL,
    menu_callback_click
  );

  #ifdef PBL_COLOR
  kana_app_simple_menu_set_color(
    ui.menu,
    GColorVeryLightBlue, GColorRichBrilliantLavender,
    GColorRichBrilliantLavender, GColorWhite);
  #endif
}

static void top_list_unload(Window* window) {
  menu_layer_destroy(ui.menu->menuLayer);
  free(ui.menu);
}

static void details_list_load(Window* window) {
  int len = kana_app_getCharCount(selectedIndex);
  for(int i=0; i < len; i++) {
    if(HIRAGANA)
      icons[i] = gbitmap_create_with_resource(kana_app_getHiraganaColRow( selectedIndex, i));
    else
      icons[i] = gbitmap_create_with_resource(kana_app_getKatakanaColRow( selectedIndex, i));

    #ifdef PBL_COLOR
      gbitmap_set_palette(icons[i], kana_app_bitmap_pallete, false);
    #endif
  }

  details_ui.menu = kana_app_simple_menu_init(
    details_ui.window,
    kana_app_act_learn_mode == HIRAGANA ? "Hiragana" : "Katakana",
    kana_app_getCharCount(selectedIndex),
    kana_app_getRow(selectedIndex),
    NULL, 
    icons, 
    NULL
  );

  #ifdef PBL_COLOR
    kana_app_simple_menu_set_color(
      details_ui.menu,
      GColorVeryLightBlue, GColorRichBrilliantLavender,
      GColorRichBrilliantLavender, GColorWhite);
  #endif
}

static void details_list_unload(Window* window) {
  for(int i = 0; i < kana_app_getCharCount(selectedIndex); i++) 
    gbitmap_destroy(icons[i]);
  menu_layer_destroy(details_ui.menu->menuLayer); 
  free(details_ui.menu); 
}

// public interface
kana_app_learn_mode_type kana_app_act_learn_mode = HIRAGANA;

void kana_app_learn_show() {
  window_stack_push(ui.window, true);
}

void kana_app_learn_init() {
  //top list
  ui.window = window_create();
  window_set_window_handlers(ui.window,
        (WindowHandlers) {
            .load = top_list_load,
            .unload = top_list_unload
        });

  //details list
  details_ui.window = window_create();
  window_set_window_handlers(details_ui.window,
        (WindowHandlers) {
            .load = details_list_load,
            .unload = details_list_unload
        });
}

void kana_app_learn_deinit() {
  window_destroy(ui.window);
  window_destroy(details_ui.window);
}
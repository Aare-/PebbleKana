#include <pebble.h>
#include "kana_app_learn.h"
#include "kana_app_glyphs.h"
#include "kana_app_resources.h"
#include "kana_app_simple_menu_color.h"

extern GColor kana_app_bitmap_pallete[2];

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
}

static void details_list_load(Window* window) {
  for(int i=0; i<kana_app_getCharCount(selectedIndex); i++) {
    icons[i] = gbitmap_create_with_resource(kana_app_getHiraganaColRow( selectedIndex, i));

    gbitmap_set_palette(icons[i], kana_app_bitmap_pallete, false);
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
  for(int i=0; i<kana_app_getCharCount(selectedIndex); i++) gbitmap_destroy(icons[i]);

  menu_layer_destroy(details_ui.menu->menuLayer);
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
  free(ui.menu);
}

/*
#include <pebble.h>
#include "learn.h"
#include "common.h"

static struct LearnUi {
	  Window* window;
	  SimpleMenuLayer* simple_menu_layer;
    SimpleMenuItem items [11];    
    SimpleMenuSection sections [1];
} ui;

static struct LearnListUi {
    Window* window;
    SimpleMenuLayer* simple_menu_layer;
  
    int numListItems;
    GBitmap *icons[5];  
    SimpleMenuItem items [5];    
    SimpleMenuSection sections [1];
} uilist;

static int selectedRow;

static void callback(int index, void *ctx) {
    selectedRow = index;
    window_stack_push(uilist.window, true);  
}

//main list
static void load(Window* window) {	
    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);

    int num_items = 0;                
    for(int i=0; i < 11; i++)       
	    ui.items[num_items++] =
	        (SimpleMenuItem) {
	            .title = getRowName(i),
	            .callback = callback
	        };

    int num_sections = 0;
    ui.sections[num_sections++] = 
        (SimpleMenuSection) {            
            .num_items = num_items,
            .items = ui.items
        };

    ui.simple_menu_layer
        = simple_menu_layer_create(bounds, window, ui.sections, num_sections, NULL);
  
    layer_add_child(window_layer, simple_menu_layer_get_layer(ui.simple_menu_layer));
}

static void unload(Window* window){
	simple_menu_layer_destroy(ui.simple_menu_layer);
}

//details list
static void list_load(Window* window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);
  
  uilist.numListItems = getCharCount(selectedRow);
  for(int i=0; i < uilist.numListItems; i++) {
    uilist.icons[i] = gbitmap_create_with_resource(getKatakana(selectedRow, i));  
    
    uilist.items[i] = 
      (SimpleMenuItem) {
          .title = getRomaji(selectedRow, i),
          .icon  = uilist.icons[i]
      };    
  }
  
  int num_sections = 0;
  uilist.sections[num_sections++] = 
      (SimpleMenuSection) {            
          .num_items = uilist.numListItems,
          .items = uilist.items
  };

  uilist.simple_menu_layer
      = simple_menu_layer_create(bounds, window, uilist.sections, num_sections, NULL);
  
  layer_add_child(window_layer, simple_menu_layer_get_layer(uilist.simple_menu_layer));
}

static void list_unload(Window* window) {
  for(int i=0; i < uilist.numListItems; i++)
    gbitmap_destroy(uilist.icons[i]);
  
  simple_menu_layer_destroy(uilist.simple_menu_layer);
}

// public interface

void kana_app_learn_init() {
	ui.window = window_create();
	window_set_window_handlers(ui.window,
        (WindowHandlers) {
            .load = load,
            .unload = unload
        });      
  
  uilist.window = window_create();
  window_set_window_handlers(uilist.window,
      (WindowHandlers) {
        .load = list_load,
        .unload = list_unload
      });
}

void kana_app_learn_show() {
	window_stack_push(ui.window, true);
}

void kana_app_learn_deinit() {
	window_destroy(ui.window);
  window_destroy(uilist.window);
}
*/

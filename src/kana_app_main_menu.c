#include <pebble.h>
#include "kana_app_main_menu.h"
#include "kana_app_settings.h"
#include "kana_app_learn.h"
#include "kana_app_quiz.h"
#include "kana_app_stats.h"

// - Start Quiz
// - Learn
// - - Hiragana
// - - Katakana
// - Settings

#define MENU_ITEMS_LEN 4

static char * menu_labels[MENU_ITEMS_LEN] = 
    {"Start Quiz", "Learn Hiragana", "Learn Katakana", "Settings"};

static MenuLayer* menu;
static Window* main_window;
static GBitmap* fuji;

static uint16_t menu_callback_get_num_sections(MenuLayer *layer, void *data) {
    return 1;
}

static uint16_t menu_callback_get_num_rows(MenuLayer *layer, uint16_t section, void *data) {
    return MENU_ITEMS_LEN;
}

static int16_t menu_callback_get_cell_height(MenuLayer *layer, MenuIndex* section, void *data) {
    return 40;
}


static int16_t menu_callback_get_header_height(MenuLayer *layer, uint16_t index, void *data) {    
    if(index == 0)
        return 55;
    return 0;
}

static void menu_callback_draw_row(GContext *ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {    
    menu_cell_basic_draw(ctx, cell_layer, menu_labels[cell_index->row], NULL, NULL);    
}

static void menu_callback_draw_header(GContext *ctx, const Layer *cell_layer, uint16_t secton_index, void *data) {    
    if(secton_index == 0) {
        GRect bounds = layer_get_frame(cell_layer);
        graphics_draw_bitmap_in_rect(ctx, fuji, bounds);
    }
}

static void menu_callback_select_click(MenuLayer* layer, MenuIndex* cell_index, void* data){
    switch(cell_index->section) {
        case 0:
            switch(cell_index->row) {
                case 0:
                    kana_app_quiz_show();
                    break;
                case 1:
                    kana_app_act_learn_mode = HIRAGANA;
                    kana_app_learn_show();
                    break;
                case 2:
                    kana_app_act_learn_mode = KATAKANA;
                    kana_app_learn_show();
                    break;                
                case 3:
                    kana_app_settings_show();
                    break;
            }
            break;
    }
}

static void load(Window* window) {
    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);

    //TODO: handle old pebble
    fuji = gbitmap_create_with_resource(RESOURCE_ID_FUJI);

    menu = menu_layer_create(bounds);
    menu_layer_set_callbacks(menu, NULL,
        (MenuLayerCallbacks) {
            .get_num_sections = menu_callback_get_num_sections,
            .get_num_rows = menu_callback_get_num_rows,

            .get_cell_height = menu_callback_get_cell_height,
            .get_header_height = menu_callback_get_header_height,            

            .draw_row = menu_callback_draw_row,
            .draw_header = menu_callback_draw_header,

            .select_click = menu_callback_select_click
        });

    #ifdef PBL_COLOR
        menu_layer_set_normal_colors(menu, GColorVeryLightBlue, GColorRichBrilliantLavender);
        menu_layer_set_highlight_colors(menu, GColorRichBrilliantLavender, GColorWhite);
    #else

    #endif

    menu_layer_set_click_config_onto_window(menu, window);
    layer_add_child(window_get_root_layer(window), menu_layer_get_layer(menu));
}

static void unload(Window* window) {
    menu_layer_destroy(menu);
}

// public interface

void kana_app_main_menu_init() {
	main_window = window_create();
    window_set_window_handlers(main_window,
        (WindowHandlers) 
        {
            .load = load,
            .unload = unload
        });      
}

void kana_app_main_menu_show() {
	  window_stack_push(main_window, true);
}

void kana_app_main_menu_deinit() {
	  window_destroy(main_window);
}

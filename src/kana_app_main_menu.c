#include <pebble.h>
#include "kana_app_main_menu.h"
/*
#include "kana_app_settings.h"
#include "kana_app_about.h"
#include "kana_app_quiz.h"
#include "kana_app_learn.h"
#include "kana_app_common.h"
*/

#define MAIN_MENU_SECTION_ITEM(__TITLE__) \
    ui.items[num_items++] =\
        (SimpleMenuItem) {\
            .title = __TITLE__,\
            .callback = callback\
        };

static struct MainMenuUI {
    Window* window;
    SimpleMenuLayer* simple_menu_layer;

    SimpleMenuItem items [5];
    SimpleMenuSection sections [1];
} ui;

static void callback(int index, void *ctx) {
    switch(index){
        case 0:
            //kana_app_quiz_show();
            break;
        case 1:
            //kana_app_learn_show();
            break;
        case 2:
            //kana_app_learn_show();
            break;
        case 3:
            //kana_app_settings_show();
            break;
        case 4:
            //kana_app_about_show();    
            break;
    }
}

static void load(Window* window) {
    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);

    int num_items = 0;    
    MAIN_MENU_SECTION_ITEM("Start Quiz")
    MAIN_MENU_SECTION_ITEM("Learn Hiragana")
    MAIN_MENU_SECTION_ITEM("Learn Katakana")
    MAIN_MENU_SECTION_ITEM("Configure")
    MAIN_MENU_SECTION_ITEM("About")

    int num_sections = 0;
    ui.sections[num_sections++] = 
        (SimpleMenuSection) {
            .title = "Kana Teacher v.0.1",
            .num_items = num_items,
            .items = ui.items
        };

    ui.simple_menu_layer
        = simple_menu_layer_create(bounds, window, ui.sections, num_sections, NULL);
  
    layer_add_child(window_layer, simple_menu_layer_get_layer(ui.simple_menu_layer));
}

static void unload(Window* window) {
    simple_menu_layer_destroy(ui.simple_menu_layer);
}

// public interface

void kana_app_main_menu_init() {
	ui.window = 
        window_create();
		    window_set_window_handlers(ui.window,
	            (WindowHandlers) 
                {
	                .load = load,
	                .unload = unload
	            });      
}

void kana_app_main_menu_show() {
	  window_stack_push(ui.window, true);
}

void kana_app_main_menu_deinit() {
	  window_destroy(ui.window);
}

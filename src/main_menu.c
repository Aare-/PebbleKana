#include <pebble.h>
#include "main_menu.h"
#include "settings.h"
#include "about.h"
#include "quiz.h"
#include "learn.h"
#include "common.h"

#define MAIN_MENU_SECTION_ITEM(__TITLE__) \
    ui.items[num_items++] =\
        (SimpleMenuItem) {\
            .title = __TITLE__,\
            .callback = callback\
        };

static struct MainMenuUI {
    Window* window;
    SimpleMenuLayer* simple_menu_layer;
    SimpleMenuItem items [4];
    SimpleMenuSection sections [1];
} ui;

static void callback(int index, void *ctx) {
    switch(index){
        case 0:
            quiz_show();
            break;
        case 1:
            learn_show();
            break;
        case 2:
            settings_show();
            break;
        case 3:
            about_show();    
            break;
    }
}

static void load(Window* window) {
    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);

    int num_items = 0;    
    MAIN_MENU_SECTION_ITEM("Start Quiz")
    MAIN_MENU_SECTION_ITEM("Learn")
    MAIN_MENU_SECTION_ITEM("Configure")
    MAIN_MENU_SECTION_ITEM("About")

    int num_sections = 0;
    ui.sections[num_sections++] = 
        (SimpleMenuSection) {
            .title = "Kana Tuts v.0.9",
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

void main_menu_init() {
	  ui.window = window_create();
		window_set_window_handlers(ui.window,
	        (WindowHandlers) {
	            .load = load,
	            .unload = unload
	        });
  
    main_menu_show();
}

void main_menu_show() {
	  window_stack_push(ui.window, true);
}

void main_menu_deinit() {
	  window_destroy(ui.window);
}

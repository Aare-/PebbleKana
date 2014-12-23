#include <pebble.h>
#include "main_menu.h"
#include "settings.h"
#include "about.h"
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
    SimpleMenuSection sections [1]
} ui;

static void callback(int index, void *ctx) {
    switch(index){
        case 0: //Start quiz

            break;
        case 1: //Learn

            break;
        case 2: //Configure
            settings_show();
      
            break;
        case 3: //About
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

}

static void unload(Window* window) {
    simple_menu_layer_destroy(ui.simple_menu_layer);
}

INIT(main_menu)
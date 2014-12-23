#include <pebble.h>
#include "learn.h"
#include "common.h"

static struct LearnUi {
	Window * window;
	SimpleMenuLayer* simple_menu_layer;
    SimpleMenuItem items [11];    
    SimpleMenuSection sections [1];
} ui;

static void load(Window* window) {	
    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);

    int num_items = 0;                
    for(int i=0; i < 11; i++)
	    ui.items[num_items++] =
	        (SimpleMenuItem) {
	            .title = char_count[i] <= 1 ? 
	            	romaji[i][0] : strcat(romaji[i][0], strcat(" - ", char_count[i] - 1)),
	            .callback = callback
	        };

    int num_sections = 0;
    ui.sections[num_sections++] = 
        (SimpleMenuSection) {
            .title = "Row:",
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

void learn_init() {
	ui.window = window_create();
	window_set_window_handlers(ui.window,
        (WindowHandlers) {
            .load = load,
            .unload = unload
        });
  
    main_menu_show();
}

void learn_show() {
	window_stack_push(ui.window, true);
}

void learn_deinit() {
	window_destroy(ui.window);
}

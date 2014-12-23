#include <pebble.h>
#include "settings.h"
#include "common.h"

static struct SettingsUi {
    Window* window;
    SimpleMenuLayer *simple_menu_layer;
    SimpleMenuItem items[2];
    SimpleMenuSection sections[1];
} ui;

static const char* quiz_types[] 
	= {"hiragana", "katakana", "both"};
static const char* quiz_answers[] 
	= {"question", "answer", "random"};

static void callback(int index, void *ctx) {	
    
}

static void load(Window* window) {
	Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);
 
    int num_items = 0;
    ui.items[num_items++] = 
    	(SimpleMenuItem) 
    	{
    		.title = "Test:",
    		.subtitle = quiz_types[0], //todo: get from storage
    		.callback = callback
    	};    

    ui.items[num_items++] = 
    	(SimpleMenuItem) 
    	{
    		.title = "Romaji as:",
    		.subtitle = quiz_answers[0], //todo: get from storage
    		.callback = callback
    	};    

    int num_sections = 0;
    ui.sections[num_sections++] = 
    	(SimpleMenuSection) 
    	{
    		.title = "Quiz settings:",
    		.items = ui.items,
    		.num_items = num_items
    	};

    ui.simple_menu_layer
    	= simple_menu_layer_create(bounds, window, ui.sections, num_sections, NULL);
  
    layer_add_child(window_layer, simple_menu_layer_get_layer(ui.simple_menu_layer));
}

static void unload(Window* window) {
	simple_menu_layer_destroy(ui.simple_menu_layer);
}

void settings_init() {
	  ui.window = window_create();
		window_set_window_handlers(ui.window,
	        (WindowHandlers) {
	            .load = load,
	            .unload = unload
	        });
}

void settings_show() {
	  window_stack_push(ui.window, true);
}

void settings_deinit() {
	  window_destroy(ui.window);
}

/*
#include <pebble.h>

#include "kana_app_settings.h"
#include "kana_app_resources.h"

static struct SettingsUi {
    Window* window;
    SimpleMenuLayer *simple_menu_layer;
    SimpleMenuItem items[1];
    SimpleMenuSection sections[1];
} ui;

static const char* quiz_types[] 
	= {"hiragana", "katakana", "both"};
static const char* quiz_answers[] 
	= {"question", "answer", "random"};
static const char* quiz_vibrations[] 
	= {"vibrate", "do nothing"};

static void callback(int index, void *ctx) {	
    switch(index){
      case 0:
        persist_write_int(STORAGE_VIBRATIONS, (persist_read_int(STORAGE_VIBRATIONS) + 1) % 2);
        ui.items[0].subtitle = quiz_vibrations[persist_read_int(STORAGE_VIBRATIONS)];
      
        break;
    }
  
    layer_mark_dirty(simple_menu_layer_get_layer(ui.simple_menu_layer));
}

static void load(Window* window) {
	Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);
 
    int num_items = 0;        
    ui.items[num_items++] = 
    	(SimpleMenuItem) 
    	{
    		.title = "On wrong answer:",
    		.subtitle = quiz_vibrations[persist_read_int(STORAGE_VIBRATIONS)],
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

// public interface

void kana_app_settings_init() {
	  ui.window = window_create();
		window_set_window_handlers(ui.window,
	        (WindowHandlers) {
	            .load = load,
	            .unload = unload
	        });
}

void kana_app_settings_show() {
	  window_stack_push(ui.window, true);
}

void kana_app_settings_deinit() {
	  window_destroy(ui.window);
}

*/

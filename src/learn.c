#include <pebble.h>
#include "learn.h"
#include "common.h"

static struct LearnUi {
	Window* window;
	SimpleMenuLayer* simple_menu_layer;
    SimpleMenuItem items [11];    
    SimpleMenuSection sections [1];
} ui;

static void callback(int index, void *ctx) {
  
}

static void load(Window* window) {	
    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);

    int num_items = 0;                
    for(int i=0; i < 11; i++) {
      char* str="";
      strcpy(str, getRomaji(i, 0));
      //strcat(str, " - ");
      
      //strcpy(name, getRomaji(i, 0));
      
      /*if(getCharCount(i) > 1) {        
        strcat(name, " - ");
        strcat(name, getRomaji(i, getCharCount(i) - 1));
      }*/
      
	    ui.items[num_items++] =
	        (SimpleMenuItem) {
	            .title = str,
	            .callback = callback
	        };
    }

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

void learn_init() {
	ui.window = window_create();
	window_set_window_handlers(ui.window,
        (WindowHandlers) {
            .load = load,
            .unload = unload
        });      
}

void learn_show() {
	window_stack_push(ui.window, true);
}

void learn_deinit() {
	window_destroy(ui.window);
}

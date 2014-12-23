#ifndef __SETTINGS_C__
#define __SETTINGS_C__

#include <pebble.h>

/** OPTIONS **/
// quiz types
static const int settings_quiz_types_num = 3;
static char* settings_quiz_types[] 
	= {"hiragana", "katakana", "both"};

// quiz types
static const int settings_quiz_answers_num = 3;
static char* settings_quiz_answers[] 
	= {"question", "answer", "random"};

static SimpleMenuItem settings_quiz_items [2];
static SimpleMenuSection settings_section [1];

Window *settings_window;
static SimpleMenuLayer *settings_main_layer; 

static void settings_quiz_config_callback(int index, void *ctx) {
	switch(index){
		case 0:
			
			//layer_mark_dirty(settings_main_layer);
			break;
	}
}

void settings_window_load(Window* window) {
	  Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);

    int num_items = 0;
    settings_quiz_items[num_items++] = 
    	(SimpleMenuItem) 
    	{
    		.title = "Test:",
    		.subtitle = settings_quiz_types[0], //todo: get from storage
    		.callback = settings_quiz_config_callback
    	};    

    settings_quiz_items[num_items++] = 
    	(SimpleMenuItem) 
    	{
    		.title = "Romaji as:",
    		.subtitle = settings_quiz_answers[0], //todo: get from storage
    		.callback = settings_quiz_config_callback
    	};    

    int num_sections = 0;
    settings_section[num_sections++] = 
    	(SimpleMenuSection) 
    	{
    		.title = "Quiz settings:",
    		.items = settings_quiz_items,
    		.num_items = num_items
    	};

    settings_main_layer
    	= simple_menu_layer_create(bounds, window, settings_section, num_sections, NULL);
  
    layer_add_child(window_layer, simple_menu_layer_get_layer(settings_main_layer));
}

void settings_window_unload(Window* window) {
	simple_menu_layer_destroy(settings_main_layer);
}

Window* settings_window_create() {
	  settings_window = window_create();    
    window_set_window_handlers(settings_window, 
        (WindowHandlers) {
            .load = settings_window_load,
            .unload = settings_window_unload
        });  
    return settings_window;
}

#endif


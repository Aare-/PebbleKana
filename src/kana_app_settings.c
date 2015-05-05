#include <pebble.h>
#include "kana_app_settings.h"
#include "kana_app_resources.h"

#define LIST_ITEMS_LEN 5

#define ADD_MENU_ITEM(TITLE, SUBTITLE) \
    ui.items[num_items++] = \
        (SimpleMenuItem) \
        { \
            .title = TITLE, \
            .subtitle = SUBTITLE, \
            .callback = callback \
        };    
#define ROTATE_OPTIONS(VARIABLE, OPTION_ID, OPTIONS, OPTIONS_LEN) \
    persist_write_int(VARIABLE, (persist_read_int(VARIABLE) + 1) % OPTIONS_LEN); \
    ui.items[OPTION_ID].subtitle = OPTIONS[persist_read_int(VARIABLE)];      

static struct SettingsUi {
    Window* window;
    SimpleMenuLayer *simple_menu_layer;
    SimpleMenuItem items[LIST_ITEMS_LEN];
    SimpleMenuSection sections[1];
} ui;


#define QUIZ_VIBRATIONS_OPTIONS_LEN 2
static const char* quiz_vibrations[] 
	= {"yes, please", "no, thanks"};
#define QUIZ_TYPE_LEN 3
static const char* quiz_type[] 
    = {"only hiragana", "only katakana", "both"};
#define QUIZ_TIME_LIMIT_OPTIONS_LEN 5
static const char* quiz_time_limit[]
    = {"no limit", "20s", "15s", "10s", "5s"};

static void callback(int index, void *ctx) {	
    switch(index){
        case 0:
            ROTATE_OPTIONS(STORAGE_VIBRATIONS, 0, quiz_vibrations, QUIZ_VIBRATIONS_OPTIONS_LEN)
            break;
        case 1:            
            ROTATE_OPTIONS(STORAGE_QUIZ_TYPE, 1, quiz_type, QUIZ_TYPE_LEN)
            break;
        case 2:
            ROTATE_OPTIONS(STORAGE_TIME_LIMIT, 2, quiz_time_limit, QUIZ_TIME_LIMIT_OPTIONS_LEN)
            break;
        case 3:

            break;
    }
  
    layer_mark_dirty(simple_menu_layer_get_layer(ui.simple_menu_layer));
}

static void load(Window* window) {
	Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);
 
    int num_items = 0;        
    
    ADD_MENU_ITEM(
        "Vibrations?",
        quiz_vibrations[persist_read_int(STORAGE_VIBRATIONS)])
    ADD_MENU_ITEM(
        "Quiz type",
        quiz_type[persist_read_int(STORAGE_QUIZ_TYPE)])
    ADD_MENU_ITEM(
        "Time Limit?",
        quiz_time_limit[persist_read_int(STORAGE_TIME_LIMIT)])
    ADD_MENU_ITEM(
        "Reset stats?", 
        "Learn from scratch")
    ADD_MENU_ITEM(
        "Credits",
        "@FilipLoster 2015"
        )

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

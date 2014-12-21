#include <pebble.h>
#include "quiz.c"

//main menu
static const char* main_menu_title = "Kana Tut v.0.9";
static SimpleMenuItem main_menu_items [4];
static SimpleMenuSection main_menu_sections [1];

static Window *main_menu_window;
static SimpleMenuLayer *main_menu_menu_layer; 

static void main_menu_item_callback(int index, void *ctx) {
    switch(index){
        case 0:

            break;
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
    }
}

#define MAIN_MENU_SECTON_ITEM(__TITLE__) \
    main_menu_items[num_items++] =\
        (SimpleMenuItem) {\
            .title = __TITLE__,\
            .callback = main_menu_item_callback\
        };

void main_menu_window_load(Window* window) {
    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);

    int num_items = 0;    
    MAIN_MENU_SECTON_ITEM("Start Quiz")
    MAIN_MENU_SECTON_ITEM("Learn")
    MAIN_MENU_SECTON_ITEM("Configure")
    MAIN_MENU_SECTON_ITEM("About")

    int num_sections = 0;
    main_menu_sections[num_sections++] = 
        (SimpleMenuSection) {
            .title = main_menu_title,
            .num_items = num_items,
            .items = main_menu_items
        };

    main_menu_menu_layer 
        = simple_menu_layer_create(bounds, window, main_menu_sections, num_sections, NULL);

}

void main_menu_window_unload(Window* window) {
    simple_menu_layer_destroy(main_menu_menu_layer);

}

int main(void){
    main_menu_window = window_create();    
    window_set_window_handlers(main_menu_window, 
        (WindowHandlers) {
            .load = main_menu_window_load,
            .unload = main_menu_window_unload
        });  
  
    //main loop
    window_stack_push(main_menu_window, true);
    app_event_loop();
  
    window_destroy(main_menu_window);
}

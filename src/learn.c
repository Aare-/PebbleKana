#include <pebble.h>
#include "learn.h"
#include "common.h"

static struct LearnUi {
	  Window* window;
	  SimpleMenuLayer* simple_menu_layer;
    SimpleMenuItem items [11];    
    SimpleMenuSection sections [1];
} ui;

static struct LearnListUi {
    Window* window;
    SimpleMenuLayer* simple_menu_layer;
  
    int numListItems;
    GBitmap *icons[5];  
    SimpleMenuItem items [5];    
    SimpleMenuSection sections [1];
} uilist;

static int selectedRow;

static void callback(int index, void *ctx) {
    selectedRow = index;
    window_stack_push(uilist.window, true);  
}

//main list
static void load(Window* window) {	
    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);

    int num_items = 0;                
    for(int i=0; i < 11; i++)       
	    ui.items[num_items++] =
	        (SimpleMenuItem) {
	            .title = getRowName(i),
	            .callback = callback
	        };

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

//details list
static void list_load(Window* window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);
  
  uilist.numListItems = getCharCount(selectedRow);
  for(int i=0; i < uilist.numListItems; i++) {
    uilist.icons[i] = gbitmap_create_with_resource(getKatakana(selectedRow, i));  
    
    uilist.items[i] = 
      (SimpleMenuItem) {
          .title = getRomaji(selectedRow, i),
          .icon  = uilist.icons[i]
      };    
  }
  
  int num_sections = 0;
  uilist.sections[num_sections++] = 
      (SimpleMenuSection) {            
          .num_items = uilist.numListItems,
          .items = uilist.items
  };

  uilist.simple_menu_layer
      = simple_menu_layer_create(bounds, window, uilist.sections, num_sections, NULL);
  
  layer_add_child(window_layer, simple_menu_layer_get_layer(uilist.simple_menu_layer));
}

static void list_unload(Window* window) {
  for(int i=0; i < uilist.numListItems; i++)
    gbitmap_destroy(uilist.icons[i]);
  
  simple_menu_layer_destroy(uilist.simple_menu_layer);
}

void learn_init() {
	ui.window = window_create();
	window_set_window_handlers(ui.window,
        (WindowHandlers) {
            .load = load,
            .unload = unload
        });      
  
  uilist.window = window_create();
  window_set_window_handlers(uilist.window,
      (WindowHandlers) {
        .load = list_load,
        .unload = list_unload
      });
}

void learn_show() {
	window_stack_push(ui.window, true);
}

void learn_deinit() {
	window_destroy(ui.window);
  window_destroy(uilist.window);
}

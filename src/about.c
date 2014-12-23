#include <pebble.h>
#include "about.h"
#include "common.h"

static struct AboutUi {
  Window *window;
  TextLayer *text_layer;
} ui;
  
static void load(Window* window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);
  
  bounds.y = bounds.y + 20;
  ui.text_layer = text_layer_create(bounds);
  text_layer_set_text(ui.text_layer, "Created by: @FilipLoster 2014");
  text_layer_set_alignment(ui.text_layer, GTextAlignmentCenter);
  
  layer_add_child(window_layer, text_layer_get_layer(ui.text_layer)); 
}

static void unload(Window* window) {

  text_layer_destroy(ui.text_layer);
  
}

void about_init() {
	  ui.window = window_create();
		window_set_window_handlers(ui.window,
	        (WindowHandlers) {
	            .load = load,
	            .unload = unload
	        });
}

void about_show() {
	  window_stack_push(ui.window, true);
}

void about_deinit() {
	  window_destroy(ui.window);
}

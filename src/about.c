#ifndef __ABOUT_C__
#define __ABOUT_C__
  
#include <pebble.h>

Window *about_window;
TextLayer *about_text_layer;
  
void about_window_load(Window* window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);
  
  about_text_layer = text_layer_create(bounds);
  text_layer_set_text(about_text_layer, "Created by: @FilipLoster 2014");
  
  layer_add_child(window_layer, text_layer_get_layer(about_text_layer)); 
}

void about_window_unload(Window* window) {
  text_layer_destroy(about_text_layer);
}

Window* about_window_create() {
  about_window = window_create();
  window_set_window_handlers(about_window,
    (WindowHandlers) {
      .load = about_window_load,
      .unload = about_window_unload
    });

  return about_window;
}
  
#endif
#include <pebble.h>
#include "kana_app_stats.h"

static struct Ui {
  Window* window;
  
  TextLayer* text;
} ui;

static void load(Window* window) {  
    
}

static void unload(Window* window) {
    
}

void kana_app_stats_init(void) {
	ui.window = window_create();
  window_set_window_handlers(ui.window,
        (WindowHandlers) {
            .load = load,
            .unload = unload
        });
}

void kana_app_stats_show(void) {
	window_stack_push(ui.window, true);
}

void kana_app_stats_deinit(void) {
	window_destroy(ui.window);
}
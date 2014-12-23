#include <pebble.h>
#include "quiz.h"
#include "common.h"

static struct QuizUi {
	Window* window;
} ui;
  
static void load(Window* window) {
  
}

static void unload(Window* window) {
  
}

void quiz_init() {
	  ui.window = window_create();
		window_set_window_handlers(ui.window,
	        (WindowHandlers) {
	            .load = load,
	            .unload = unload
	        });
}

void quiz_show() {
	  window_stack_push(ui.window, true);
}

void quiz_deinit() {
	  window_destroy(ui.window);
}

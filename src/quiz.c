#include <pebble.h>
#include "quiz.h"
#include "common.h"

static struct QuizUi {
	Window* window;
	ActionBarLayer *action_bar;

	GBitmap *image_top;
	GBitmap *image_middle;
	GBitmap *image_bottom;
} ui;

static unloadAnswerOptions();

static loadRandomAnswerOptions() {
	ui.image_top    = gbitmap_create_with_resource(katakana[0]);
	ui.image_middle = gbitmap_create_with_resource(katakana[1]);
	ui.image_bottom = gbitmap_create_with_resource(katakana[2]);

	action_bar_layer_set_icon(ui.action_bar, BUTTON_ID_UP,     &ui.image_top);
	action_bar_layer_set_icon(ui.action_bar, BUTTON_ID_SELECT, &ui.image_middle);
	action_bar_layer_set_icon(ui.action_bar, BUTTON_ID_DOWN,   &ui.image_bottom);
}

static void click_up(ClickRecognizerRef recognizer, void *context) {
	unloadAnswerOptions();
	loadRandomAnswerOptions();
}

static void click_select(ClickRecognizerRef recognizer, void *context) {
	unloadAnswerOptions();
	loadRandomAnswerOptions();	
}

static void click_down(ClickRecognizerRef recognizer, void *context) {
	unloadAnswerOptions();
	loadRandomAnswerOptions();
}

static click_config_provider(void *context) {	
	window_single_click_subscribe(BUTTON_ID_UP, click_up);
	window_single_click_subscribe(BUTTON_ID_SELECT, click_select);
	window_single_click_subscribe(BUTTON_ID_DOWN, click_down);
}

static unloadAnswerOptions() {
	gbitmap_destroy(ui.image_top);
	gbitmap_destroy(ui.image_middle);
	gbitmap_destroy(ui.image_bottom);
}

static void load(Window* window) {
  	ui.action_bar = action_bar_layer_create();
  	action_bar_layer_add_to_window(window);
  	action_bar_layer_set_click_config_provider(
  		ui.action_bar,
  		click_config_provider);

  	loadRandomAnswerOptions();
}

static void unload(Window* window) {
	unloadAnswerOptions();
  	action_bar_layer_destroy(ui.action_bar);
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

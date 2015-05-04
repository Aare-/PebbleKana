/*
#include <pebble.h>
#include "kana_app_quiz.h"
#include "kana_app_resources.h"

static struct QuizUi {
	Window* window;
	ActionBarLayer *action_bar;
  //Layer* timeProgress;

	GBitmap *image_top;
	GBitmap *image_middle;
	GBitmap *image_bottom;
  
  TextLayer* text;
} ui;

static void unloadAnswerOptions();

static int answer[3][2];
static bool enabled[3];
static int correct;

static int timeLimit;
static float timeLeft;

static void loadRandomAnswerOptions() {  
  for(int i = 0; i < 3; i++) {        
    enabled[i] = true;
    
    bool test = false;
    do{
      answer[i][0] = rand() % 11; 
      answer[i][1] = rand() % getCharCount(answer[i][0]);
      test = false;
      for(int j=0; j<i; j++)
        if(answer[i][0] == answer[j][0] && 
           answer[i][1] == answer[j][1]) {
          test = true;
          break;
        }
    }while(test);
  }
  
  correct = rand() % 3;  
  
	ui.image_top    = gbitmap_create_with_resource(getKatakana(answer[0][0], answer[0][1]));
	ui.image_middle = gbitmap_create_with_resource(getKatakana(answer[1][0], answer[1][1]));
	ui.image_bottom = gbitmap_create_with_resource(getKatakana(answer[2][0], answer[2][1]));
    
  text_layer_set_text(ui.text, getRomaji(answer[correct][0], answer[correct][1]));

	action_bar_layer_set_icon(ui.action_bar, BUTTON_ID_UP,     ui.image_top);
	action_bar_layer_set_icon(ui.action_bar, BUTTON_ID_SELECT, ui.image_middle);
	action_bar_layer_set_icon(ui.action_bar, BUTTON_ID_DOWN,   ui.image_bottom);    
}

static void click_up(ClickRecognizerRef recognizer, void *context) {
  if(correct != 0) {
    if(enabled[0]) {
      enabled[0] = false;
      if(persist_read_int(STORAGE_VIBRATIONS) == 0)
        vibes_short_pulse();
      action_bar_layer_clear_icon(ui.action_bar, BUTTON_ID_UP);
    }
  } else {  
	  unloadAnswerOptions();
	  loadRandomAnswerOptions();
  }
}

static void click_select(ClickRecognizerRef recognizer, void *context) {
  if(correct != 1) {
    if(enabled[1]){
      enabled[1] = false;
      if(persist_read_int(STORAGE_VIBRATIONS) == 0)
        vibes_short_pulse();      
      action_bar_layer_clear_icon(ui.action_bar, BUTTON_ID_SELECT);
    }
  } else {  
  	unloadAnswerOptions();
  	loadRandomAnswerOptions();	
  }
}

static void click_down(ClickRecognizerRef recognizer, void *context) {
  if(correct != 2) {
    if(enabled[2]) {
      enabled[2] = false;
      if(persist_read_int(STORAGE_VIBRATIONS) == 0)
        vibes_short_pulse();
      action_bar_layer_clear_icon(ui.action_bar, BUTTON_ID_DOWN);
    }
  } else {
  	unloadAnswerOptions();
  	loadRandomAnswerOptions();
  }
}

static void click_config_provider(void *context) {	
	window_single_click_subscribe(BUTTON_ID_UP, click_up);
	window_single_click_subscribe(BUTTON_ID_SELECT, click_select);
	window_single_click_subscribe(BUTTON_ID_DOWN, click_down);
}

static void unloadAnswerOptions() {
	gbitmap_destroy(ui.image_top);
	gbitmap_destroy(ui.image_middle);
	gbitmap_destroy(ui.image_bottom);
}

static void time_update(Layer *layer, GContext* ctx) {

}

static void load(Window* window) {  
    switch(persist_read_int(STORAGE_TIME_LIMIT)){    
      case 1: timeLimit = 10; break;
      case 2: timeLimit = 5; break;
      case 3: timeLimit = 2; break;
      case 4: timeLimit = 1; break;
      default: timeLimit = 0; break;
    }
  
    GFont custom_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ROMAJI_50));
    GRect bounds = GRect(10, 40, 100, 60);           
    ui.text = text_layer_create(bounds);
    text_layer_set_font(ui.text, custom_font);
    text_layer_set_text(ui.text, "");
    text_layer_set_text_alignment(ui.text, GTextAlignmentCenter);
  
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(ui.text)); 
  
  	ui.action_bar = action_bar_layer_create();
  	action_bar_layer_add_to_window(ui.action_bar, window);
  	action_bar_layer_set_click_config_provider(
  		ui.action_bar,
  		click_config_provider);    
  
  	loadRandomAnswerOptions();
}

static void unload(Window* window) {
	  unloadAnswerOptions();
  	action_bar_layer_destroy(ui.action_bar);
    text_layer_destroy(ui.text);
}

// public interface

void kana_app_quiz_init() {
	  ui.window = window_create();
		window_set_window_handlers(ui.window,
	        (WindowHandlers) {
	            .load = load,
	            .unload = unload
	        });
}

void kana_app_quiz_show() {
	  window_stack_push(ui.window, true);
}

void kana_app_quiz_deinit() {
	  window_destroy(ui.window);
}

*/

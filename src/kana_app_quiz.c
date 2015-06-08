#include <pebble.h>
#include <pebble_fonts.h>
#include "kana_app_quiz.h"
#include "kana_app_resources.h"
#include "kana_app_glyphs.h"

#define GLYPH_DIMENSIONS 120

static struct Ui {
  Window *window;
  
  Layer *glyph_layer;

  int act_glyph;
  int glyph_paths_num;
  GPath *glyph_path[ MAX_GLYPH_SEGMENTS ];

  TextLayer* text;

  TextLayer* answer_top;  
  TextLayer* answer_middle;
  TextLayer* answer_bottom;
} ui;

static void bg_update_proc(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);

  GRect rect_bottom = bounds;

  graphics_context_set_fill_color(ctx, GColorVeryLightBlue);
  graphics_fill_rect(ctx, rect_bottom, 0, GCornerNone);
}

static void glyph_layer_update_proc(Layer *layer, GContext *ctx) {    
  GRect bounds = layer_get_bounds(layer);
  GPoint center = GPoint(bounds.size.w / 2 - 50, 0);

  for(int i=0; i < ui.glyph_paths_num; i++) {
    gpath_move_to(ui.glyph_path[i], center);

    graphics_context_set_fill_color(ctx, GColorRichBrilliantLavender);
    graphics_context_set_stroke_color(ctx, GColorRichBrilliantLavender);
    gpath_draw_filled(ctx, ui.glyph_path[i]); 
  }
}

static void reload_answers() {
  text_layer_set_text(ui.answer_top, kana_app_getRomaji(rand() % ALPHABET_ROW_NUM, rand() % 5));
  text_layer_set_text(ui.answer_middle, kana_app_getRomaji(rand() % ALPHABET_ROW_NUM, rand() % 5));
  text_layer_set_text(ui.answer_bottom, kana_app_getRomaji(rand() % ALPHABET_ROW_NUM, rand() % 5));
}

static void display_glyph(int glyphId) {
  if(glyphId == ui.act_glyph) return;

  for(int i=0; i < ui.glyph_paths_num; i++)
    gpath_destroy(ui.glyph_path[i]);

  ui.act_glyph = glyphId;

  if(ui.act_glyph < 0)
    ui.act_glyph = 0;
  if(ui.act_glyph >= GLYPHS_NUM)
    ui.act_glyph = GLYPHS_NUM - 1;

  //ui.glyph_paths_num = kana_app_katakana_glyphs[ui.act_glyph].size;
  ui.glyph_paths_num = kana_app_hiragana_glyphs[ui.act_glyph].size;

  for(int i = 0; i < ui.glyph_paths_num; i++) {
    ui.glyph_path[i] 
      //= gpath_create(kana_app_katakana_glyphs[ui.act_glyph].glyph_path[i]);
      = gpath_create(kana_app_hiragana_glyphs[ui.act_glyph].glyph_path[i]);
  }

  //todo: change this
  reload_answers();

  layer_mark_dirty(window_get_root_layer(ui.window));
}

static void down_click(ClickRecognizerRef recognizer, void *context) {
  display_glyph(ui.act_glyph + 1);
}

static void up_click(ClickRecognizerRef recognizer, void *context) {
  display_glyph(ui.act_glyph - 1);
}

static void config_provider(void *ctx) {
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click);
  window_single_click_subscribe(BUTTON_ID_UP, up_click);
}

static void load(Window* window) {    
  Layer *window_layer = window_get_root_layer(ui.window);
  GRect window_bounds = layer_get_bounds(window_layer);
  layer_set_update_proc(window_layer, bg_update_proc);

  // init text layers
  ui.answer_top = text_layer_create(GRect(144 - 34, 84 - 40 - 18, 30, 18));
  text_layer_set_text_alignment(ui.answer_top, GTextAlignmentRight);
  text_layer_set_font(ui.answer_top, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text(ui.answer_top, "");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(ui.answer_top)); 
  
  ui.answer_middle = text_layer_create(GRect(144 - 34, 84 - 9, 30, 18));
  text_layer_set_text_alignment(ui.answer_middle, GTextAlignmentRight);
  text_layer_set_font(ui.answer_middle, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text(ui.answer_middle, "");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(ui.answer_middle)); 

  ui.answer_bottom = text_layer_create(GRect(144 - 34, 84 + 40, 30, 18));
  text_layer_set_text_alignment(ui.answer_bottom, GTextAlignmentRight);
  text_layer_set_font(ui.answer_bottom, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text(ui.answer_bottom, "");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(ui.answer_bottom)); 

  // init icons
  GRect icon_rect = GRect(0, 0, window_bounds.size.w, window_bounds.size.h);
  grect_align(&icon_rect, &window_bounds, GAlignCenter, false);
  ui.glyph_layer = layer_create(icon_rect);
  layer_set_update_proc(ui.glyph_layer, glyph_layer_update_proc);
  layer_set_clips(ui.glyph_layer, true);

  layer_add_child(window_layer, ui.glyph_layer);
  window_set_click_config_provider(ui.window, (ClickConfigProvider) config_provider);

  display_glyph(0);
}

static void unload(Window* window) {
  layer_destroy(ui.glyph_layer);
}

void kana_app_quiz_init() {
  ui.window = window_create();
  ui.act_glyph = -1;
  ui.glyph_paths_num = 0;

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

/*
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

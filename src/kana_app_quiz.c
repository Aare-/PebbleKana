#include <pebble.h>
#include "kana_app_quiz.h"
#include "kana_app_resources.h"

#define GLYPH_DIMENSIONS 120

static struct Ui {
  Window *window;
  
  Layer *glyph_layer;
  GPath *glyph_path;
  int act_glyph;

  TextLayer* text;
} ui;

#define GLYPH_SIZE 12

static const GPathInfo PATHS[GLYPH_SIZE] = 
  { 
    {
      .num_points = 19,
      .points = (GPoint[]) {{14,20}, {16,31}, {95,29}, {82,45}, {68,54}, {68,44}, {57,42}, {53,74}, {42,93}, {30,102}, {37,113}, {53,96}, {64,77}, {66,57}, {73,66}, {95,49}, {106,33}, {112,28}, {100,19}}
    },
    {
      .num_points = 13,
      .points = (GPoint[]) {{25,57}, {63,39}, {89,15}, {101,-2}, {112,5}, {94,25}, {83,36}, {88,36}, {87,101}, {75,101}, {75,44}, {50,61}, {30,70}}
    },
    {
      .num_points = 18,
      .points = (GPoint[]) {{62,41}, {54,41}, {51,0}, {86,0}, {86,-21}, {99,-21}, {99,0}, {129,0}, {138,7}, {132,39}, {108,70}, {75,82}, {70,70}, {90,68}, {112,52}, {124,29}, {124,13}, {62,12}}
    },
    {
      .num_points = 12,
      .points = (GPoint[]) {{47,48}, {48,59}, {80,58}, {81,107}, {34,107}, {35,117}, {139,117}, {139,107}, {94,107}, {94,59}, {126,59}, {126,50}}
    },
    {
      .num_points = 21,
      .points = (GPoint[]) {{58,62}, {65,71}, {93,48}, {115,21}, {116,68}, {113,69}, {104,66}, {99,76}, {118,80}, {127,75}, {126,13}, {164,12}, {163,2}, {127,2}, {127,-24}, {116,-22}, {117,1}, {59,1}, {59,11}, {106,12}, {83,40}}
    },
    {
      .num_points = 21,
      .points = (GPoint[]) {{31,59}, {34,71}, {69,68}, {56,101}, {34,124}, {43,134}, {67,104}, {79,68}, {108,68}, {106,112}, {101,117}, {88,114}, {84,125}, {104,130}, {114,121}, {119,62}, {112,56}, {81,57}, {80,32}, {69,31}, {70,57}}
    },
    {
      .num_points = 20,
      .points = (GPoint[]) {{43,36}, {48,55}, {14,60}, {18,70}, {48,66}, {53,88}, {10,94}, {14,105}, {56,99}, {66,138}, {78,134}, {69,98}, {107,92}, {104,81}, {66,90}, {60,64}, {93,59}, {91,51}, {59,57}, {54,36}}
    },
    {
      .num_points = 17,
      .points = (GPoint[]) {{35,39}, {23,66}, {4,85}, {11,95}, {30,79}, {36,63}, {70,62}, {60,93}, {35,117}, {7,125}, {12,137}, {47,119}, {68,99}, {84,60}, {75,51}, {40,51}, {46,39}}
    },
    {
      .num_points = 19,
      .points = (GPoint[]) {{63,29}, {58,53}, {48,72}, {33,87}, {41,94}, {65,65}, {93,65}, {90,87}, {80,106}, {53,118}, {58,129}, {83,117}, {97,100}, {104,74}, {104,65}, {131,64}, {131,53}, {68,54}, {76,31}}
    },
    {
      .num_points = 10,
      .points = (GPoint[]) {{67,74}, {68,84}, {136,84}, {135,130}, {68,130}, {67,140}, {136,140}, {136,145}, {148,145}, {148,71}}
    },
    {
      .num_points = 23,
      .points = (GPoint[]) {{30,31}, {30,55}, {4,55}, {4,64}, {29,64}, {32,91}, {41,89}, {41,66}, {71,65}, {67,92}, {40,111}, {45,122}, {67,109}, {78,94}, {81,66}, {110,65}, {109,56}, {83,56}, {83,25}, {70,26}, {70,54}, {40,55}, {38,29}}
    },
    {
      .num_points = 20,
      .points = (GPoint[]) {{34,46}, {60,42}, {83,28}, {112,-9}, {122,-2}, {102,24}, {71,48}, {37,59}, {34,46}, {24,0}, {50,15}, {57,4}, {29,-11}, {24,0}}
    }
  };

static void bg_update_proc(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);

  GRect rect_bottom = bounds;

  graphics_context_set_fill_color(ctx, GColorVeryLightBlue);
  graphics_fill_rect(ctx, rect_bottom, 0, GCornerNone);
}

static void glyph_layer_update_proc(Layer *layer, GContext *ctx) {    
  graphics_context_set_fill_color(ctx, GColorRichBrilliantLavender);
  gpath_draw_filled(ctx, ui.glyph_path);
}

static void display_glyph(int glyphId) {
  if(ui.glyph_path != NULL)
    gpath_destroy(ui.glyph_path);
  ui.act_glyph = glyphId;
  if(ui.act_glyph < 0)
    ui.act_glyph = 0;
  if(ui.act_glyph >= GLYPH_SIZE)
    ui.act_glyph = GLYPH_SIZE - 1;

  ui.glyph_path = gpath_create(&PATHS[ui.act_glyph]);
  layer_mark_dirty(window_get_root_layer(ui.window));
}

static void down_click(ClickRecognizerRef recognizer, void *context) {
  display_glyph(ui.act_glyph - 1);
}

static void up_click(ClickRecognizerRef recognizer, void *context) {
  display_glyph(ui.act_glyph + 1);
}

static void config_provider(void *ctx) {
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click);
  window_single_click_subscribe(BUTTON_ID_UP, up_click);
}

static void load(Window* window) {    
  Layer *window_layer = window_get_root_layer(ui.window);
  GRect window_bounds = layer_get_bounds(window_layer);
  layer_set_update_proc(window_layer, bg_update_proc);

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

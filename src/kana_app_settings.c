#include <pebble.h>
#include "kana_app_settings.h"
#include "kana_app_resources.h"
#include "kana_app_simple_menu_color.h"
#include "kana_app_simple_menu_color.h"

static SimpleColorMenuLayer *simpleMenu;

#define LIST_TITLES_LEN 4

static char* setting_cell_titles[LIST_TITLES_LEN]
    = {"Vibrations?", "Quiz type", "Romaji as", "Credits"};
static char* setting_cell_sel_subtitles[LIST_TITLES_LEN];

static int setting_subtitles_len[LIST_TITLES_LEN] = 
    {2, 3, 2, 1};

static char* setting_cell_subtitles [LIST_TITLES_LEN][3] =
    {
     {"yes, please", "no, thanks", ""},
     {"hiragana", "katakana", "random"},
     {"answers", "questions", ""},     
     {"@FilipLoster 2015", "", ""}
    };

static void menu_rotate_option(int position) {    
    int prevValue = kana_app_settings_get_setting(position);

    persist_write_int( SETTINGS_STORAGE + position, (prevValue + 1) % setting_subtitles_len[position]);
}

static char* menu_get_option(int position) {
    return setting_cell_subtitles[position][kana_app_settings_get_setting(position)];
}

static void menu_callback_click(MenuLayer* layer, MenuIndex* index, void* data) {
    menu_rotate_option(index->row);
    (simpleMenu->cellItemsSubtitle)[index->row] = menu_get_option(index->row);
    layer_mark_dirty(menu_layer_get_layer(simpleMenu->menuLayer));
}

// public interface

void kana_app_settings_init() {	
    for(int i=0; i < LIST_TITLES_LEN; i++)
        setting_cell_sel_subtitles[i] = menu_get_option(i);

    simpleMenu = kana_app_simple_menu_init(
        window_create(),
        "Settings",
        LIST_TITLES_LEN,
        setting_cell_titles,
        setting_cell_sel_subtitles,
        NULL,
        menu_callback_click
      );

    #ifdef PBL_COLOR
    kana_app_simple_menu_set_color(
        simpleMenu,
        GColorVeryLightBlue, GColorRichBrilliantLavender,
        GColorRichBrilliantLavender, GColorWhite);
    #endif
}

void kana_app_settings_show() {
	window_stack_push(simpleMenu->window, true);
}

void kana_app_settings_deinit() {
    window_destroy(simpleMenu->window);
    free(simpleMenu);
}

int kana_app_settings_get_setting(int key) {
    int storPosition = SETTINGS_STORAGE + key;
    return persist_exists(storPosition) ? persist_read_int(storPosition) % setting_subtitles_len[key] : 0;
}
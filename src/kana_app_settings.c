#include <pebble.h>
#include "kana_app_settings.h"
#include "kana_app_resources.h"
#include "kana_app_simple_menu_color.h"
#include "kana_app_simple_menu_color.h"

static struct SimpleColorMenuLayer *simpleMenu;

#define LIST_TITLES_LEN 5

static char* setting_cell_titles[LIST_TITLES_LEN]
    = {"Vibrations?", "Quiz type", "Time Limit?", "Reset stats?", "Credits"};
static char* setting_cell_sel_subtitles[LIST_TITLES_LEN];

static int setting_subtitles_len[LIST_TITLES_LEN] = 
    {2, 3, 5, 1, 1};

static char* setting_cell_subtitles [LIST_TITLES_LEN][5] =
    {
     {"yes, please", "no, thanks", "", "", ""},
     {"only hiragana", "only katakana", "both", "", ""},
     {"no limit", "20s", "15s", "10s", "5s"},
     {"Learn from scratch", "", "", "", ""},
     {"@FilipLoster 2015", "", "", "", ""}
    };

static void menu_rotate_option(int position) {
    int storPosition = SETTINGS_STORAGE + position;
    int prevValue = persist_exists(storPosition) ? 
        persist_read_int(storPosition) : 0;

    persist_write_int( storPosition, (prevValue + 1) % setting_subtitles_len[position]);
}

static char* menu_get_option(int position) {
    int storPosition = SETTINGS_STORAGE + position;
    int actPos = persist_exists(storPosition) ? persist_read_int(storPosition) % setting_subtitles_len[position] : 0;

    return setting_cell_subtitles[position][actPos];
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
        menu_callback_click
      );

    #ifdef PBL_COLOR
    kana_app_simple_menu_set_color(
        simpleMenu,
        GColorLiberty, GColorRichBrilliantLavender,
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

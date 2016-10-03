#pragma once

typedef struct {
	int menuItemsLen;
    MenuLayer* menuLayer;
    Window* window;

    char* title;
	int headerHeight;

	int cellHeight;
    char** cellItemsTitle;
    char** cellItemsSubtitle;
    GBitmap** icons;
} SimpleColorMenuLayer;

SimpleColorMenuLayer *kana_app_simple_menu_init (
	Window*, char*, int, char**, char**, GBitmap**, void (*sel_click_callback)(MenuLayer*, MenuIndex*, void*));

#ifdef PBL_COLOR
void kana_app_simple_menu_set_color (
	SimpleColorMenuLayer *, GColor, GColor, GColor, GColor);
#endif
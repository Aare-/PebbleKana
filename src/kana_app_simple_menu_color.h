#pragma once

struct SimpleColorMenuLayer {
	int menuItemsLen;
    MenuLayer* menuLayer;
    Window* window;

    char* title;
	int headerHeight;

	int cellHeight;
    char** cellItemsTitle;
    char** cellItemsSubtitle;
};

struct SimpleColorMenuLayer *kana_app_simple_menu_init (
	Window*, char*, int, char**, char**, void (*sel_click_callback)(MenuLayer*, MenuIndex*, void*));
void kana_app_simple_menu_set_color (
	struct SimpleColorMenuLayer *, GColor, GColor, GColor, GColor);
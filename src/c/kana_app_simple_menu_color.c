#include <pebble.h>
#include "kana_app_simple_menu_color.h"

static uint16_t mc_get_num_sections(MenuLayer *layer, void *data) {
    return 1;
}

static uint16_t mc_get_num_rows(MenuLayer *layer, uint16_t section, void *data) {
	SimpleColorMenuLayer *layerData = ( SimpleColorMenuLayer*)data;	
    return layerData->menuItemsLen;
}

static int16_t mc_get_cell_height(MenuLayer *layer, MenuIndex* section, void *data) {
	SimpleColorMenuLayer *layerData = (SimpleColorMenuLayer*)data;
    return layerData->cellHeight;
}

static int16_t mc_get_header_height(MenuLayer *layer, uint16_t index, void *data) {    
	SimpleColorMenuLayer *layerData = (SimpleColorMenuLayer*)data;

    if(index == 0 && layerData->title != NULL)
        return layerData->headerHeight;
    return 0;
}

static void mc_draw_row(GContext *ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {    
	SimpleColorMenuLayer *layerData = (SimpleColorMenuLayer *)data;

    menu_cell_basic_draw(
    	ctx, 
    	cell_layer,     	
    	(layerData->cellItemsTitle)[cell_index->row], 
    	(layerData->cellItemsSubtitle) == NULL ? 
            NULL : (layerData->cellItemsSubtitle)[cell_index->row], 
    	layerData->icons == NULL ? 
            NULL : (layerData->icons)[cell_index->row]);    
}

static void mc_draw_header(GContext *ctx, const Layer *cell_layer, uint16_t section_index, void *data) {    
	SimpleColorMenuLayer *layerData = (SimpleColorMenuLayer *)data;

    if(section_index == 0 && layerData->title != NULL) {
        menu_cell_basic_header_draw(
        	ctx,
        	cell_layer,
        	layerData->title);
    }
}

SimpleColorMenuLayer *kana_app_simple_menu_init (
		Window* window, 
        char* title,
		int numItems,
		char** cellItemsTitle, 
		char** cellItemsSubtitle,		
        GBitmap** cellIcons,
		void (*sel_click_callback)(MenuLayer*, MenuIndex*, void*)) {

	Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);

	SimpleColorMenuLayer *mStruct = malloc(sizeof(SimpleColorMenuLayer));
	
	mStruct->window = window;
	mStruct->menuItemsLen = numItems;
	mStruct->menuLayer = menu_layer_create(bounds);
	mStruct->headerHeight = MENU_CELL_BASIC_HEADER_HEIGHT;
	mStruct->cellHeight = 40;
    mStruct->title = title;
	mStruct->cellItemsTitle = cellItemsTitle;
	mStruct->cellItemsSubtitle = cellItemsSubtitle;
    mStruct->icons = cellIcons;

	menu_layer_set_callbacks(
		mStruct->menuLayer, 
		mStruct, 
		(MenuLayerCallbacks) {
			.get_num_sections = mc_get_num_sections,
            .get_num_rows = mc_get_num_rows,

            .get_cell_height = mc_get_cell_height,
            .get_header_height = mc_get_header_height,            

            .draw_row = mc_draw_row,
            .draw_header = mc_draw_header,

            .select_click = sel_click_callback,
		});

    menu_layer_set_click_config_onto_window(
        mStruct->menuLayer, 
        mStruct->window);
    layer_add_child(
        window_get_root_layer(mStruct->window), 
        menu_layer_get_layer(mStruct->menuLayer));

	return mStruct;
}

#ifdef PBL_COLOR
void kana_app_simple_menu_set_color (
		SimpleColorMenuLayer *layerData, 
		GColor backColor, 
		GColor frontColor, 
		GColor highlightBackColor, 
		GColor highlightFrontColor) {
    
    menu_layer_set_normal_colors(
    	layerData->menuLayer, 
    	backColor, 
    	frontColor);

    menu_layer_set_highlight_colors(
    	layerData->menuLayer, 
    	highlightBackColor, 
    	highlightFrontColor);        
}
#endif

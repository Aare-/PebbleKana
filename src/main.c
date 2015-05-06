#include <pebble.h>
#include "kana_app_main_menu.h"
#include "kana_app_quiz.h"
#include "kana_app_settings.h"
#include "kana_app_learn.h"
#include "kana_app_stats.h"

void init() {
    kana_app_quiz_init();
    kana_app_learn_init();
    kana_app_settings_init();
    kana_app_stats_init();
    kana_app_main_menu_init();
}

void deinit() {  
    kana_app_main_menu_deinit();
    kana_app_quiz_deinit();
    kana_app_settings_deinit();
    kana_app_learn_deinit();
    kana_app_stats_deinit();
}

int main(void) {     
    srand(time(NULL));

    init();    
    kana_app_main_menu_show();

    app_event_loop();
    deinit();
    
    return 0;
}

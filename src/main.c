#include <pebble.h>
#include "main_menu.h"
#include "quiz.h"
#include "settings.h"
#include "about.h"

void init() {
    quiz_init();
    settings_init();
    about_init();
    main_menu_init();
}

void deinit() {  
    main_menu_deinit();
    quiz_deinit();
    settings_deinit();
    about_deinit();
}

int main(void) {     
    init();    

    app_event_loop();

    deinit();
    
    return 0;
}

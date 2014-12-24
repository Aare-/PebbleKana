#include <pebble.h>
#include "main_menu.h"
#include "quiz.h"
#include "settings.h"
#include "about.h"
#include "learn.h"

void init() {
    quiz_init();
    settings_init();
    about_init();
    learn_init();
    main_menu_init();
}

void deinit() {  
    main_menu_deinit();
    quiz_deinit();
    settings_deinit();
    learn_deinit();
    about_deinit();
}

int main(void) {     
    srand(time(NULL));
    init();    

    app_event_loop();

    deinit();
    
    return 0;
}

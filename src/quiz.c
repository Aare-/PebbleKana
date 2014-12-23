#ifndef __QUIZ_C__
#define __QUIZ_C__

#include <pebble.h>

Window* quiz_window;  
  
void quiz_window_load(Window* window) {
  
}

void quiz_window_unload(Window* window) {
  
}

Window* quiz_window_create() {
  	quiz_window = window_create();
   	window_set_window_handlers(quiz_window,
      	(WindowHandlers) {
        	.load = quiz_window_load,
        	.unload = quiz_window_unload
      	});
  
  	return quiz_window;
}

#endif

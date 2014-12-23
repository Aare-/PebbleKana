#pragma once

#define INIT(__PREFIX__)\
	void __PREFIX___init() {\
	    ui.window = window_create();\
		window_set_window_handlers(ui.window,\ 
	        (WindowHandlers) {\
	            .load = load,\
	            .unload = unload\
	        });\
	}\
	void __PREFIX___show() {\
	  window_stack_push(ui.window, true);\
	}\
	void __PREFIX___deinit() {\
	  window_destroy(ui.window);\
	}
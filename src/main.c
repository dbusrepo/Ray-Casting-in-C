#include <stdio.h>
#include <stdlib.h>
#include "../X11-C-Graphics/src/app/app.h"

static app_t *app;

static void update(int64_t elapsed_time)
{
}

static void draw(void)
{
	app_clear_screen(app);
	app_show_fps(app, 0, 0);
}

static void key_event(int key, int action)
{
	if (action == KEY_PRESS) {
		switch (key)
		{
		case KEY_ESC:
		{
			app_stop(app);
			break;
		}
		case KEY_F1:
		{
			app_toggle_fullscreen(app);
			break;
		}
		}
	}
}

static void finish(void)
{
}

int main()
{
	screen_settings_t *screen_settings = malloc(sizeof(screen_settings_t));
	screen_settings->window_title = "Ray Casting";
	screen_settings->width = 1366;
	screen_settings->height = 768;
	screen_settings->targetFps = 60;
	screen_settings->show_stats = true;
	screen_settings->fullscreen = false;
	app = app_init(screen_settings);
	app_callbacks_t *cbs = malloc(sizeof(app_callbacks_t));
	cbs->key_fun = key_event;
	cbs->update = update;
	cbs->draw = draw;
	cbs->finish = finish;
	cbs->print_final_stats = NULL;
	app_run(app, cbs);
	free(screen_settings);
	free(cbs);
}

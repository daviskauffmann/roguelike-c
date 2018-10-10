#ifndef ENGINE_H
#define ENGINE_H

#include <libtcod/libtcod.h>

#define WINDOW_TITLE "Roguelike v0.1"
#define FPS 60

enum engine_state
{
    ENGINE_STATE_MENU,
    ENGINE_STATE_PLAYING
};

struct engine
{
    enum engine_state state;
    bool should_quit;
};

int engine_run(void);

#endif
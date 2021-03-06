#ifndef WORLD_H
#define WORLD_H

#include <libtcod.h>

#include "map.h"
#include "spell.h"

#define NUM_MAPS 60

struct world
{
    TCOD_random_t random;
    unsigned int time;
    struct map maps[NUM_MAPS];
    struct actor *player;
    struct actor *hero;
    bool hero_dead;
    TCOD_list_t messages;
};

extern struct world *world;

void world_setup(void);
void world_cleanup(void);
void world_create(struct actor *hero);
void world_save(const char *filename);
void world_load(const char *filename);
void world_update(float delta_time);
void world_log(int floor, int x, int y, TCOD_color_t color, char *fmt, ...);

#endif

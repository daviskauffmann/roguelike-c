#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include <libtcod.h>

#include "world.h"

typedef struct
{
    tiletype_t type;
    bool seen;
} tiledata_t;

typedef struct
{
    uint8_t x;
    uint8_t y;
    uint8_t w;
    uint8_t h;
} roomdata_t;

typedef struct
{
    bool is_player;
    uint8_t x;
    uint8_t y;
    uint8_t glyph;
    TCOD_color_t color;
    uint8_t sight_radius;
} actordata_t;

typedef struct
{
    uint8_t stair_down_x;
    uint8_t stair_down_y;
    uint8_t stair_up_x;
    uint8_t stair_up_y;
    tiledata_t tiledata[MAP_WIDTH][MAP_HEIGHT];
    uint8_t room_count;
    roomdata_t *roomdata;
    uint8_t actor_count;
    actordata_t *actordata;
} mapdata_t;

typedef struct
{
    uint8_t map_count;
    mapdata_t *mapdata;
} worlddata_t;

typedef struct
{
    TCOD_random_t random;
    uint8_t current_map_index;
    worlddata_t *worlddata;
} gamedata_t;

extern world_t *world;
extern uint8_t current_map_index;
extern map_t *current_map;
extern actor_t *player;

void game_init(void);
void game_load(void);
void game_save(void);

#endif
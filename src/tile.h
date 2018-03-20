#ifndef TILE_H
#define TILE_H

#include <libtcod/libtcod.h>

typedef enum {
    TILE_EMPTY,
    TILE_FLOOR,
    TILE_WALL,
    TILE_DOOR_CLOSED,
    TILE_DOOR_OPEN,
    TILE_STAIR_DOWN,
    TILE_STAIR_UP,

    NUM_TILE_TYPES
} TileType;

typedef struct
{
    TCOD_color_t shadow_color;
} TileCommon;

typedef struct
{
    const char *name;
    unsigned char glyph;
    TCOD_color_t color;
    bool is_walkable;
    bool is_transparent;
} TileInfo;

typedef struct
{
    TileType type;
    bool seen;
    TCOD_list_t objects;
    TCOD_list_t actors;
    TCOD_list_t items;
} Tile;

void tile_init(Tile *tile, TileType type, bool seen);
void tile_reset(Tile *tile);

#endif

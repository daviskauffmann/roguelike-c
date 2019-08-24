#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include <libtcod.h>

enum race_size;

struct item_common
{
    char __placeholder;
};

enum base_item
{
    BASE_ITEM_BATTLEAXE,
    BASE_ITEM_CLUB,
    BASE_ITEM_DAGGER,
    BASE_ITEM_GREATAXE,
    BASE_ITEM_GREATSWORD,
    BASE_ITEM_HALBERD,
    BASE_ITEM_HEAVY_CROSSBOW,
    BASE_ITEM_KATANA,
    BASE_ITEM_LARGE_SHIELD,
    BASE_ITEM_LIGHT_CROSSBOW,
    BASE_ITEM_LONGBOW,
    BASE_ITEM_LONGSWORD,
    BASE_ITEM_MACE,
    BASE_ITEM_POTION,
    BASE_ITEM_QUARTERSTAFF,
    BASE_ITEM_SCIMITAR,
    BASE_ITEM_SHORTBOW,
    BASE_ITEM_SHORTSWORD,
    BASE_ITEM_SMALL_SHIELD,
    BASE_ITEM_SPEAR,
    BASE_ITEM_TOWER_SHIELD,
    BASE_ITEM_WARHAMMER,

    NUM_BASE_ITEMS
};

enum equip_slot
{
    EQUIP_SLOT_NONE,
    EQUIP_SLOT_ARMOR,
    EQUIP_SLOT_BELT,
    EQUIP_SLOT_BOOTS,
    EQUIP_SLOT_CLOAK,
    EQUIP_SLOT_GLOVES,
    EQUIP_SLOT_HELMET,
    EQUIP_SLOT_MAIN_HAND,
    EQUIP_SLOT_OFF_HAND,

    NUM_EQUIP_SLOTS
};

struct equip_slot_info
{
    char *name;
    char *label; // TODO: not the biggest fan of this solution
};

enum damage_type
{
    DAMAGE_TYPE_ACID,
    DAMAGE_TYPE_BLUDGEONING,
    DAMAGE_TYPE_COLD,
    DAMAGE_TYPE_DIVINE,
    DAMAGE_TYPE_ELECTRICAL,
    DAMAGE_TYPE_FIRE,
    DAMAGE_TYPE_MAGICAL,
    DAMAGE_TYPE_NEGATIVE,
    DAMAGE_TYPE_PIERCING,
    DAMAGE_TYPE_POSITIVE,
    DAMAGE_TYPE_SLASHING,
    DAMAGE_TYPE_SONIC
};

enum weapon_size
{
    WEAPON_SIZE_LARGE,
    WEAPON_SIZE_MEDIUM,
    WEAPON_SIZE_SMALL,
    WEAPON_SIZE_TINY
};

struct base_item_info
{
    unsigned char glyph;
    TCOD_color_t color;
    float weight;
    enum equip_slot equip_slot;
    enum damage_type damage_type;
    enum weapon_size weapon_size;
    bool ranged;
    int num_dice;
    int die_to_roll;
    int crit_threat;
    int crit_mult;
    int base_cost;
    int stack;
    int base_ac;
    int armor_check_penalty;
    int arcane_spell_failure;
    int starting_charges;
};

enum item_type
{
    ITEM_TYPE_BATTLEAXE,
    ITEM_TYPE_BATTLEAXE_1,
    ITEM_TYPE_CLUB,
    ITEM_TYPE_CLUB_1,
    ITEM_TYPE_DAGGER,
    ITEM_TYPE_DAGGER_1,
    ITEM_TYPE_GREATAXE,
    ITEM_TYPE_GREATAXE_1,
    ITEM_TYPE_GREATSWORD,
    ITEM_TYPE_GREATSWORD_1,
    ITEM_TYPE_HALBERD,
    ITEM_TYPE_HALBERD_1,
    ITEM_TYPE_HEAVY_CROSSBOW,
    ITEM_TYPE_HEAVY_CROSSBOW_1,
    ITEM_TYPE_KATANA,
    ITEM_TYPE_KATANA_1,
    ITEM_TYPE_LARGE_SHIELD,
    ITEM_TYPE_LARGE_SHIELD_1,
    ITEM_TYPE_LIGHT_CROSSBOW,
    ITEM_TYPE_LIGHT_CROSSBOW_1,
    ITEM_TYPE_LONGBOW,
    ITEM_TYPE_LONGBOW_1,
    ITEM_TYPE_LONGSWORD,
    ITEM_TYPE_LONGSWORD_1,
    ITEM_TYPE_MACE,
    ITEM_TYPE_MACE_1,
    ITEM_TYPE_POTION_CURE_LIGHT_WOUNDS,
    ITEM_TYPE_QUARTERSTAFF,
    ITEM_TYPE_QUARTERSTAFF_1,
    ITEM_TYPE_SCIMITAR,
    ITEM_TYPE_SCIMITAR_1,
    ITEM_TYPE_SHORTBOW,
    ITEM_TYPE_SHORTBOW_1,
    ITEM_TYPE_SHORTSWORD,
    ITEM_TYPE_SHORTSWORD_1,
    ITEM_TYPE_SMALL_SHIELD,
    ITEM_TYPE_SMALL_SHIELD_1,
    ITEM_TYPE_SPEAR,
    ITEM_TYPE_SPEAR_1,
    ITEM_TYPE_TOWER_SHIELD,
    ITEM_TYPE_TOWER_SHIELD_1,
    ITEM_TYPE_WARHAMMER,
    ITEM_TYPE_WARHAMMER_1,

    NUM_ITEM_TYPES
};

struct item_info
{
    enum base_item base_item;
    const char *name;
    const char *description;
    TCOD_list_t item_properties;
};

struct item
{
    enum item_type type;
    int floor;
    int x;
    int y;
};

struct item *item_new(enum item_type type, int floor, int x, int y);
void item_delete(struct item *item);
bool item_is_two_handed(struct item *item, enum race_size race_size);

#endif

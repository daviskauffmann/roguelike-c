#include "item_property.h"

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct ac_bonus *ac_bonus_new(enum ac ac, int bonus)
{
    struct ac_bonus *ac_bonus = malloc(sizeof(struct ac_bonus));
    assert(ac_bonus);
    struct base_item_property *base_item_property = (struct base_item_property *)ac_bonus;
    base_item_property->item_property = ITEM_PROPERTY_AC_BONUS;
    ac_bonus->ac = ac;
    ac_bonus->bonus = bonus;
    return ac_bonus;
}

void ac_bonus_delete(struct ac_bonus *ac_bonus)
{
    free(ac_bonus);
}

struct enhancement_bonus *enhancement_bonus_new(int bonus)
{
    struct enhancement_bonus *enhancement_bonus = malloc(sizeof(struct enhancement_bonus));
    assert(enhancement_bonus);
    struct base_item_property *base_item_property = (struct base_item_property *)enhancement_bonus;
    base_item_property->item_property = ITEM_PROPERTY_ENHANCEMENT_BONUS;
    enhancement_bonus->bonus = bonus;
    return enhancement_bonus;
}

void enhancement_bonus_delete(struct enhancement_bonus *enhancement_bonus)
{
    free(enhancement_bonus);
}

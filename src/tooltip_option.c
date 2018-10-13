#include <libtcod/libtcod.h>
#include <malloc.h>
#include <string.h>

#include "tooltip_option.h"

#include "CMemleak.h"

struct tooltip_option *tooltip_option_create(char *text, bool (*fn)(struct game *game, struct input *input, struct tooltip_data data), struct tooltip_data data)
{
    struct tooltip_option *tooltip_option = calloc(1, sizeof(struct tooltip_option));

    tooltip_option->text = strdup(text);
    tooltip_option->fn = fn;
    tooltip_option->data = data;

    return tooltip_option;
}

void tooltip_option_destroy(struct tooltip_option *tooltip_option)
{
    free(tooltip_option->text);
    free(tooltip_option);
}

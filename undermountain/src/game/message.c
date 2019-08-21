#include "message.h"

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

struct message *message_create(char *text, TCOD_color_t color)
{
    struct message *message = malloc(sizeof(struct message));
    assert(message);
    message->text = strdup(text);
    message->color = color;
    return message;
}

void message_destroy(struct message *message)
{
    free(message->text);
    free(message);
}

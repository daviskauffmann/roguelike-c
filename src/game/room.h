#ifndef ROOM_H
#define ROOM_H

struct room
{
    int x;
    int y;
    int w;
    int h;
};

struct room *room_new(int x, int y, int w, int h);
void room_delete(struct room *room);
void room_get_random_pos(struct room *room, int *x, int *y);

#endif

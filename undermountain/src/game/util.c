#include "util.h"

#include <math.h>

float distance_between_sq(int x1, int y1, int x2, int y2)
{
    float dx = (float)(x1 - x2);
    float dy = (float)(y1 - y2);
    return powf(dx, 2) + powf(dy, 2);
}

float distance_between(int x1, int y1, int x2, int y2)
{
    return sqrtf(distance_between_sq(x1, y1, x2, y2));
}

float angle_between(int x1, int y1, int x2, int y2)
{
    float dx = (float)(x1 - x2);
    float dy = (float)(y1 - y2);
    return atan2f(dy, dx);
}

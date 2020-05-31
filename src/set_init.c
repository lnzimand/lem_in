#include "../lem_in.h"

void set_init(List *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data))
{
    list_init(set, destroy);
    set->match = match;
    return;
}
#include "../lem_in.h"

void    path_init(Path *path, void (*destroy)(void *data))
{
    path->size = 0;
    path->destroy = destroy;
    path->head = NULL;
    path->tail = NULL;

    return;
}

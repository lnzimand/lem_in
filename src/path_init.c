#include "../lem_in.h"

void    path_init(Path *path)
{
    path->size = 0;
    path->head = NULL;
    path->tail = NULL;

    return;
}

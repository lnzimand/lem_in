#include "../lem_in.h"

int queue_dequeue(List *queue, void **data)
{
    return list_rem_next(queue, NULL, data);
}
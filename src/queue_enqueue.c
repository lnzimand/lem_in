#include "../lem_in.h"

int queue_enqueue(List *queue, const void *data)
{
    return list_ins_next(queue, list_tail(queue), data);
}
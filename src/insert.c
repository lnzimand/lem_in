#include "../lem_in.h"

int set_insert(List *set, const void *data)
{
    if (set_is_member(set, data))
        return 1;
    return list_ins_next(set, list_tail(set), data);
}
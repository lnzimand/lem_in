#include "../lem_in.h"

int set_insert(List *set, const void *data)
{
    /*****************************************************************************
    *  Do not allow the insertion of duplicates.                                 *
    ******************************************************************************/
    if (set_is_member(set, data))
        return 1;
    /*****************************************************************************
    *  Insert the data.                                                          *
    ******************************************************************************/
    return list_ins_next(set, list_tail(set), data);
}
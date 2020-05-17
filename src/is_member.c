#include "../lem_in.h"

int set_is_member(const List *set, const void *data)
{
    list_elmt    *member;

    /*****************************************************************************
    *  Determine if the data is a member of the set.                             *
    ******************************************************************************/
    member = list_head(set);
    while ( member != NULL) {
        if (set->match(data, list_data(member)))
            return 1;
        member = list_next(member);
    }
    return 0;
}
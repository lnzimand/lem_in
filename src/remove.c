#include "../lem_in.h"

/*****************************************************************************
*  ------------------------------ set_remove ------------------------------  *
******************************************************************************/
int set_remove(List *set, void **data)
{
    list_elmt       *member;
    list_elmt       *prev;

    /*****************************************************************************
    *  Find the member to remove.                                                *
    ******************************************************************************/
    prev = NULL;
    member = list_head(set);
    while (member != NULL)
    {
        if (set->match(*data, list_data(member)))
            break;
        prev = member;
        member = list_next(member);
    }
    /*****************************************************************************
    *  Return if the member was not found.                                       *
    ******************************************************************************/
    if (member == NULL)
        return -1;
    /*****************************************************************************
    *  Remove the member.                                                        *
    ******************************************************************************/
    return list_rem_next(set, prev, data);
}
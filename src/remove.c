#include "../lem_in.h"

/*****************************************************************************
*  ------------------------------ set_remove ------------------------------  *
******************************************************************************/

int     list_rem_next_tweaked(List *list, list_elmt *element);

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
    return list_rem_next_tweaked(set, prev);
}

int     list_rem_next_tweaked(List *list, list_elmt *element)
{
    list_elmt       *old_element;

    // if the list is empty
    if (!list_size(list))
        return (-1);
    if (!element)
    {
        // Hanlde removal from the head of the list
        old_element = list->head;
        list->head = list->head->next;
        if (list_size(list) == 1)
            list->tail = NULL;
    }
    else
    {
        // Handle removal from somewhere other than head
        if (!element->next)
            return (-1);
        old_element = element->next;
        element->next = element->next->next;
        if (!element->next)
            list->tail = element;
    }
    free(old_element);
    list->size--;
    return (0);
}
#include "../lem_in.h"

int     list_rem_next(List *list, list_elmt *element, void **data)
{
    list_elmt       *old_element;

    if (!list_size(list))
        return (-1);
    if (!element)
    {
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;
        if (list_size(list) == 1)
            list->tail = NULL;
    }
    else
    {
        if (!element->next)
            return (-1);
        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;
        if (!element->next)
            list->tail = element;
    }
    free(old_element);
    list->size--;
    return (0);
}
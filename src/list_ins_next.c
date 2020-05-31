#include "../lem_in.h"

int     list_ins_next(List *list, list_elmt *element, const void *data)
{
    list_elmt       *new_element;

    if (!(new_element = (list_elmt*)malloc(sizeof(list_elmt))))
        return (-1);
    new_element->data = (void*)data;
    if (!element)
    {
        if (!list_size(list))
            list->tail = new_element;
        new_element->next = list->head;
        list->head = new_element;
    }
    else
    {
        if (!(element->next))
            list->tail = new_element;
        new_element->next = element->next;
        element->next = new_element;
    }
    list->size++;
    return (0);
}
#include "../lem_in.h"

int     path_rem_next(Path *path, path_elmt *element, void **data)
{
    path_elmt       *old_element;

    if (!path_size(path))
        return (-1);
    if (!element)
    {
        *data = path->head->ant_name;
        old_element = path->head;
        path->head = path->head->next;
        if (path_size(path) == 1)
            path->tail = NULL;
    }
    else
    {
        if (!element->next)
            return (-1);
        *data = element->next->ant_name;
        old_element = element->next;
        element->next = element->next->next;
        if (!element->next)
            path->tail = element;
    }
    free(old_element);
    path->size--;
    return (0);
}
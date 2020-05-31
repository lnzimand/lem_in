#include "../lem_in.h"

int     path_ins_next(Path *path, path_elmt *element, const void *data)
{
    path_elmt   *new_element;
    path_elmt   *head;

    if (!(new_element = (path_elmt*)malloc(sizeof(path_elmt))))
        return (-1);
    new_element->room_name = (void*)data;
    new_element->occupied = 0;
    new_element->prev = NULL;
    if (!element)
    {
        if (!path_size(path))
            path->tail = new_element;
        new_element->next = path->head;
        if (path_head(path) != NULL)
        {
            head = path_head(path);
            head->prev = new_element;
        }
        path->head = new_element;
    }
    else
    {
        if (!(element->next))
            path->tail = new_element;
        new_element->next = element->next;
        element->next = new_element;
    }
    path->size++;
    return (0);
}

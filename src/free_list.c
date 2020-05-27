#include "../lem_in.h"

void    free_list_elmt(list_elmt *head)
{
    list_elmt   *element;

    while (head != NULL)
    {
        element = head;
        head = list_next(head);
        free(element);
    }
}
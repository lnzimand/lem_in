#include "../lem_in.h"

void    store_link(char *str, list_elmt **head)
{
    list_elmt   *temp;
    list_elmt   *element;

    if (!(*head))
    {
        *head = link_alloc();
        (*head)->data = ft_strdup(str);
    }
    else
    {
        temp = *head;
        element = link_alloc();
        while (temp->next)
            temp = temp->next;
        element->data = ft_strdup(str);
        temp->next = element;
    }
}
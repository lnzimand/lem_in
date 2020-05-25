#include "../lem_in.h"

void    print_list(List *list)
{
    list_elmt   *element;

    element = list_head(list);
    while (element != NULL)
    {
        ft_putendl(element->data);
        element = list_next(element);
    }
}
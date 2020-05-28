#include "../lem_in.h"

void    verify_connections(List *hops, void *end, void *start)
{
    list_elmt   *element;

    element = list_head(hops);
    while (element != NULL)
    {
        if (match(element->data, end) || match(element->data, start))
            error_handler("NO POSSIBLE SOLUTION ", "End/Start NOT CONNECTED!");
        element = list_next(element);
    }
    
}
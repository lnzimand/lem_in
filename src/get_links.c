#include "../lem_in.h"

void   get_links(char **arr, list_elmt **head)
{
    while (*arr)
    {
        if (ft_strchr(*arr, '-'))
            store_link(*arr, head);
        arr++;
    }
}
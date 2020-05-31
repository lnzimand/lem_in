#include "../lem_in.h"

void   get_links(char **arr, List *head)
{
    while (*arr)
    {
        if (ft_strchr(*arr, '-'))
            list_ins_next(head, NULL, *arr);
        arr++;
    }
}
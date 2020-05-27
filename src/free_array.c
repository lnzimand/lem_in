#include "../lem_in.h"

void    free_array(char **arr)
{
    char    *temp;
    char    **holder;

    holder = arr;
    while (*arr)
    {
        temp = *arr;
        arr++;
        ft_strdel(&temp);
    }
    free(holder);
}
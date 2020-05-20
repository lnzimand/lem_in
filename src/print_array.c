#include "../lem_in.h"

void    print_array(char **arr)
{
    while (*arr)
    {
        ft_putendl(*arr);
        arr++;
    }
}
#include "../lem_in.h"

int     get_number_of_ants(char **arr)
{
    char    *temp;
    char    *holder;

    temp = ft_strtrim(*arr);
    holder = temp;
    if (!temp)
    {
        ft_strdel(&temp);
        free_array(arr);
        error_handler("ants number ", "INCORRECT INPUT!");
    }
    while (*temp)
    {
        if (!ft_isdigit(*temp))
        {
            ft_strdel(&holder);
            free_array(arr);
            error_handler("ants number ", "INCORRECT INPUT!");
        }
        temp++;
    }
    return ft_atoi(holder);
}

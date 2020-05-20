#include "../lem_in.h"

int     get_number_of_ants(char *str)
{
    char    *temp;

    temp = ft_strtrim(str);
    if (!temp)
        error_handler("ants number ", "INCORRECT INPUT!");
    while (*temp)
    {
        if (!ft_isdigit(*temp))
            error_handler("ants number ", "INCORRECT INPUT!");
        temp++;
    }
    return ft_atoi(str);
}

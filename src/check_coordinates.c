#include "../lem_in.h"

void    check_coordinates(char *position, char *str)
{
    if (ft_strchr(++str, ' '))
    {
        str = ft_strchr(++str, ' ');
        if (!ft_isdigit(*++str))
            error_handler(position, " INCORRECT INPUT!");
    }
    else
        error_handler(position, " INCORRECT INPUT!");
    
}
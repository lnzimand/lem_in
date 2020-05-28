#include "../lem_in.h"

int     correct_coord(char *str)
{
    if (ft_strchr(++str, ' '))
    {
        str = ft_strchr(++str, ' ');
        if (!ft_isdigit(*++str))
            return 0;
    }
    else
        return 0;
    return 1;
}